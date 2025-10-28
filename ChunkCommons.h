CHUNK_COMMONS_H:
namespace Chunk
{
    struct vdb_data {
        std::vector<float> flatVD;
        std::string vendor;
        std::string model;
        size_t dim = 0;
        size_t n = 0;
        //----------------------------------------------------
        inline const std::tuple<size_t, size_t>  getPar(void) const{return { n, dim };}; 
        inline std::pair<std::string, std::string>getEmbPar(void) const{return { vendor , model };}; 
        inline const float* getVDpointer(void) const{
            if (flatVD.empty()) {
                std::cout << "[Info] Empty Vector Data Base\n";
                return {};
            }
            return flatVD.data();
        }; 
    };
    
    extern inline const std::unordered_map<std::string, std::vector<std::string>> EmbeddingModel = {
            {"openai", {"text-embedding-ada-002", "text-embedding-3-small", "..."}},
            {"huggingface", {"bge-small", "bge-large"}},
            {"cohere", {"embed-english-light-v3.0"}}
        };
 
    inline void PrintEmbeddingModels() {
        std::cout << "╔══════════════════════════════════════════════════════════╗\n";
        std::cout << "║               📦 Available Embedding Models              \n";
        std::cout << "╠══════════════════════════════════════════════════════════╣\n";

        for (const auto& [vendor, models] : EmbeddingModel) {
            std::cout << "║ 🔸 Vendor: " << vendor << "\n";
            for (const auto& model : models) {
                std::cout << "║    └── " << model << "\n";
            }
            std::cout << "╠──────────────────────────────────────────────────────────╣\n";
        }

        std::cout << "╚══════════════════════════════════════════════════════════╝\n";
    }


    inline std::string to_lowercase(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(),
                    [](unsigned char c) { return std::tolower(c); });
        return str;
    }

    inline std::optional<std::string> resolve_vendor_from_model(const std::string& model) {
        for (const auto& [vendor, models] : EmbeddingModel) {
            if (std::find(models.begin(), models.end(), model) != models.end()) {
                return vendor;
            }
        }
        return std::nullopt;
    }

    inline bool resolve_vendor(const std::string& v) {
        for (const auto& [vendor, _] : EmbeddingModel) {
            if (vendor == v) return true;
        }
        return false;
    }
    
    inline size_t allChunksHaveEmbeddings(const std::vector<RAGLibrary::Document>& chunks_list) {
        if (chunks_list.empty()) return 0;

        const size_t ref_dim = chunks_list[0].embedding->size();

        // Validate all
        bool consistent = std::all_of(
            chunks_list.begin(),
            chunks_list.end(),
            [ref_dim](const RAGLibrary::Document& doc) {
                return doc.embedding.has_value() &&
                    doc.embedding->size() == ref_dim;
            });

        return consistent ? ref_dim : 0;
    }
    
    inline void InitAPIKey() {
        const char* env_key = std::getenv("OPENAI_API_KEY");
        if (env_key == nullptr) {
            #ifdef DEBUG
                std::cerr << "Erro: API key not set.\n";
            #endif
            throw std::runtime_error("API key not set. Please set the OPENAI_API_KEY environment variable.");
        }
        #ifdef DEBUG
        std::cerr << "API key set\n";
        #endif
    }
    std::vector<RAGLibrary::Document> Embeddings(const std::vector<RAGLibrary::Document>& list, std::string model);
   
    ...
}



//-----------------------------------------------------------------------------------------------------------
CHUNK_COMMONS_CPP:

std::vector<RAGLibrary::Document> Chunk::Embeddings(const std::vector<RAGLibrary::Document>& list, std::string model)
{     
    std::vector<RAGLibrary::Document> emb;

    std::optional<std::string> vendor_opt = Chunk::resolve_vendor_from_model(model);
    if (!vendor_opt.has_value()) {
        throw std::invalid_argument("Model not supported.");
    }
    std::string vendor = vendor_opt.value();

    if (vendor == "openai") {
        int count = 0;
        Chunk::InitAPIKey();
        do {
            try {
                auto client = std::make_unique<EmbeddingOpenAI::EmbeddingOpenAI>();
                emb = client->GenerateEmbeddings(list, model);
            } catch (const std::exception& e) {
                std::cerr << "[OpenAI::GenerateEmbeddings exception] "
                          << e.what() << " (attempt " << count + 1 << ")\n";
            }
            count++;
        } while (!Chunk::allChunksHaveEmbeddings(emb) && count < 3);

        if (!Chunk::allChunksHaveEmbeddings(emb)) {
            throw std::runtime_error("Failed to generate valid embeddings after 3 attempts.");
        }

        return emb;
    }

    // futuros vendors podem entrar aqui
    //else if (vendor == "huggingface") {
        //auto client = std::make_unique<EmbeddingHF::EmbeddingHF>();
        //emb = client->GenerateEmbeddings(list, m_model);
        //return emb;
    //}

    throw std::runtime_error("Vendor handler for '" + vendor + "' not implemented.");
}

