## Hospital Registration
## Build
1. Crear una carpeta build: ``mkdir build && cd build``
2. Instalar dependencias con Conan: ``conan install .. [--build=missing]``
3. Ejecutar CMake:
  - Test: ``cmake -DTEST=OFF [-DCMAKE_BUILD_TYPE=Debug] .. ``
  - App: ``cmake -DTEST=ON [-DCMAKE_BUILD_TYPE=Debug] .. ``
  La configuración de Debug incluye google sanitizers
4. Compilar ``make``
## Run
### Test:
- Dentro de build ejecutar ``make test`` o
- Desde el root. ``./bin/Test``
### App:
- Desde el root ``./bin/main``
