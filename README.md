# PureCPP


This is an open-source modular RAG (Retrieval-Augmented Generation) system developed by PureAI, to which I contributed during my internship, integrating C++ and Python, deploying to PyPI, and optimizing for high-performance vector processing and queries.
It also includes careful memory control strategies to maximize performance, culminating in the development of a functional and scalable vector database engine.
In addition to its modular architecture, the project features orchestration and optimization through build and deploy pipeline scripts, reducing processes that originally took ~3 hours down to just 30 minutes.

> **Note:**  
> As this project is extensive and contains many modular components, this documentation will initially focus on explaining the parts I developed in the `ChunkDefault` and `ChunkQuery` modules, as well as their integration with the `VectorDatabase`.  
> 
> Later sections will extend the documentation to cover:
> - the C++ <-> Python bindings,
> - the modular CMake architecture,
> - and the automated PIP build and deployment system.
The Preview:🔗[ Upcoming New Version ](https://github.com/bbzaffari/purecpp), under tests before its official release under the PURE Ecosystem.
---
## Table of Contents

- [Introduction](#purecpp)
- [Main Contributions](#main-contributions)
- [Related Files and Areas](#related-files-and-areas)
- [Technologies Used](#technologies-used)
- [Functionality](#functionality)
- [Disclaimer](#disclaimer)


## Main Contributions

- Developed the entire backbone architecture of the core system, focusing on efficient construction and high-performance execution.
-  Implemented nearly all C++ <-> Python bindings, enabling seamless integration between the core engine and Python interfaces.
- Built and optimized the build and deploy pipeline, reducing process time from ~3 hours to just 30 minutes.
- Created a Docker environment for isolated, reproducible development and usage.
-  Restructured the repository for better modularity, scalability, and maintainability.
-  Designed and implemented the core vector database engine, ensuring scalable, functional vector storage and retrieval.
-  Developed cosine similarity query implementations, integrated with FAISS for optimized similarity search.
## Related Files and Areas

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
  - All files related to C++/Python bindings integration.
    
-  CMake:
  - All files and configurations with uppercase **CMake** in their name, including modular build configurations.
    

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
In summary, I designed and implemented all the core structures related to the deploy system and PIP packaging, building the backbone that supports the project's modular distribution and automation.
Additionally, I engineered and integrated the fundamental data structures (structs) that gave rise to the engine powering the Vector Database — a scalable, high-performance core explained further in the documentation.


## Core Vector Database Engine
Focusing on:

- `ChunkDefault`
- `ChunkQuery`
- `VectorDatabase`
  
## High-Level Functionality Demonstration
I have created a Jupyter Notebook that explains the high-level functionality of this components that I implemented 
This notebook demonstrates how these components work together and highlights the key aspects of the three main libraries involved. [Click here to access the notebook directory](https://github.com/bbzaffari/Lightning-Fast-RAG-Core-PureAI-s-PureCPP-VDB)
or [https://colab.research.google.com/github/bbzaffari/Lightning-Fast-RAG-Core-PureAI-s-PureCPP-VDB/blob/main/chunk_VDB.ipynb](https://colab.research.google.com/github/bbzaffari/Lightning-Fast-RAG-Core-PureAI-s-PureCPP-VDB/blob/main/chunk_VDB.ipynb)

## Low-Level Functionality

> **NOTE:**  
> Initially, I created these structures and functions in the directory `Chunk/ChunkCommons/ChunkCommons.h`.  
> I will provide further details and explanations about this part later.



## Disclaimer
These contributions reflect technical solutions I personally implemented, outside the formal scope of my internship contract, using no internal company resources. No confidential or proprietary information is disclosed here; all content is based on public open-source work.

This repository contains code I developed during my time collaborating with PureAI.
Officially, my role was focused on testing tasks; however, over time, I contributed far beyond what was initially requested.

I developed:
- the backbone architecture for VDB engine,
- C++ <-> Python bindings,
- modular chunk and embedding systems,
- all pypi integration
- and automation scripts for build and deployment.


While formally an intern, I undertook responsibilities typically associated with intermediate-level engineering roles. 
Part of this publication is to ensure that my contributions are visible.

**License & Visibility** 

The repository is public under the MIT license.
Everything shared here reflects parts I personally worked on or played a significant role in developing.
There is no confidential or proprietary information being revealed here:
1. The code is already publicly available,
2. My intent is to explain and clarify the parts I directly contributed to,
3. I aim to provide technical transparency and highlight the complexities often hidden behind raw code.
