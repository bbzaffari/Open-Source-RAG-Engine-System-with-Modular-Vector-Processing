# PureCPP


This is an open-source modular RAG (Retrieval-Augmented Generation) system developed by PureAI, to which I contributed during my internship, integrating C++ and Python, deploying to PyPI, and optimizing for high-performance vector processing and querying.
It also includes careful memory control strategies to maximize performance, culminating in the development of a functional and scalable vector database engine.
In addition to its modular architecture, the project features orchestration and optimization through build and deploy pipeline scripts, reducing processes that originally took ~3 hours down to just 30 minutes.

> **Note:**  
> As this project is extensive and contains many modular components, this documentation will initially focus on explaining the parts I developed in the `ChunkDefault` and `ChunkQuery` modules, as well as their integration with the `VectorDatabase`.  
> 
> Later sections will extend the documentation to cover:
> - The C++ <-> Python bindings 🔗[Purecpp Refactor: Scratch Pad ](https://github.com/bbzaffari/purecpp_sp);
> - The modular CMake architecture🔗[Purecpp Refactor: Scratch Pad ](https://github.com/bbzaffari/purecpp_sp);
> - [🔗 Automated PIP build and `legacy deployment` system.](https://github.com/bbzaffari/Deploy-System/)


---
## Table of Contents

- [Introduction](#purecpp)
- [Main Contributions](#main-contributions)
- [Related Files and Areas](#related-files-and-areas)
- [Technologies Used](#technologies-used)
- [Functionality](#functionality)
- [Disclaimer](#disclaimer)

## Main Contributions

- Implemented nearly all **C++ <-> Python bindings**, enabling seamless integration between the **core C++** and **Python**.
- Implemented and optimized the **build-and-deploy pipeline**, reducing process time from ~3 hours to just **30 minutes**.
- Created a **Docker environment** for **isolated**, **reproducible development** and usage.
- Restructured the **repository** for better **modularity**, **scalability**, and **maintainability**.
- Designed and implemented the **core vector database engine**, ensuring **scalable**, **functional vector storage** and **retrieval**.
- Developed **cosine similarity query implementations**, integrated with **FAISS** for **optimized similarity search**.
- Developed of the **backbone architecture** of the core query system, focusing on **efficient construction** and **high-performance execution**.

## Related Files and Areas
*The Preview:🔗[Purecpp Refactor: Scratch Pad ](https://github.com/bbzaffari/purecpp_sp), under tests before its official release under the PURE Ecosystem.*
- All `PIP_*` folders:
  - Scripts and configurations for Python packaging and deployment.
  
- All automation scripts (`*.sh`):
  - Build, deploy, and environment orchestration scripts.

- Core modules:
  - `VectorDatabase`
  - `ChunkDefault`
  - `ChunkQuery`

- Documentation:
  - All documentation related to my file/directories
    
- Bindings:
  - All files related to C++/Python bindings integration
    
- CMake:
  - All files and configurations with uppercase **CMake** in their name, including modular build configurations
    

## Technologies Used

- **CMake** — Modular build system configuration.
- **Conan** — C++ package and dependency management.
- **Torch / PyTorch** — Machine learning and tensor operations.
- **C++** — Core implementation language.
- **Rust** — Auxiliary or experimental components.
- **Docker** — Containerization for reproducible environments.
- **ManyLinux** — Multi-Python-version builds and compatibility for pip wheels.
-  **Ninja** — Fast build system used with CMake for compilation.
-  **PyBind11** — C++ <-> Python bindings.
- **FAISS** — Vector similarity search (used in cosine similarity, L2, inner product queries).
- **RE2** — High-performance regular expressions.
-  **OpenAI API (EmbeddingOpenAI)** — For generating embeddings via models like `text-embedding-ada-002`.
-  **OpenMP** — Parallelization for multi-threaded C++ code.
- **OpenBLAS** — Optimized linear algebra backend for matrix operations.
- **ONNX** — Open Neural Network Exchange for model interoperability.
  


# FUNCTIONALITY

## Core Vector Database Engine
I engineered and integrated the fundamental data structures that gave rise to the engine powering the Vector Database — scalable and high-performance core.

Focusing on:
  * `ChunkDefault`
  * `ChunkQuery`
  * `VectorDatabase`
  
### High-Level Functionality Demonstration
I have created a Jupyter Notebook that explains the high-level functionality of this components that I implemented 
This notebook demonstrates how these components work together and highlights the key aspects of the three main libraries involved.
[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/bbzaffari/Lightning-Fast-RAG-Core-PureAI-s-PureCPP-VDB/blob/main/chunk_VDB.ipynb) or  [Click here to access the notebook directory](https://github.com/bbzaffari/Lightning-Fast-RAG-Core-PureAI-s-PureCPP-VDB)

### Low-Level Functionality

> **NOTE:**  
> Initially, I created these structures and functions in the directory `Chunk/ChunkCommons/ChunkCommons.h`.  
> I will provide further details and explanations about this part later.


---
---
---
# Disclaimer
These contributions reflect technical solutions I personally implemented, outside the formal scope of my internship contract, using no internal company resources. No confidential or proprietary information is disclosed here; all content is based on public open-source work.

This repository contains code I developed during my time collaborating with PureAI.
Officially, my role was focused on testing tasks; however, over time, I contributed far beyond what was initially requested, because is a startup.

I developed:
- the backbone architecture for VDB engine,
- C++ <-> Python bindings,
- modular chunk and embedding systems,
- all pypi integration
- and automation scripts for build and deployment.


While formally an intern, I undertook responsibilities typically associated with intermediate-level engineering roles. 

**License & Visibility** 

The repository is public under the MIT license.
Everything shared here reflects parts I personally worked on or played a significant role in developing.
There is no confidential or proprietary information being revealed here:
1. The code is already publicly available,
2. My intent is to explain and clarify the parts I directly contributed to,
3. I aim to provide technical transparency and highlight the complexities often hidden behind raw code.
