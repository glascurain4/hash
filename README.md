# Uso de Hashes con Resolución Cuadrática

Este repositorio contiene una implementación de tablas hash con resolución de colisiones utilizando un esquema cuadrático. Este proyecto forma parte de una tarea académica y muestra cómo aplicar conceptos avanzados de estructuras de datos.

## Archivos

### 1. **quadratic.h**
Este archivo define la clase `Quadratic`, una implementación genérica de una tabla hash con resolución de colisiones cuadrática.

- **Características principales:**
  - Plantilla genérica que permite usar cualquier tipo de llave y valor.
  - Resolución de colisiones mediante **pruebas cuadráticas**.
  - Métodos clave:
    - `put(Key, Value)`: Inserta un par llave-valor en la tabla hash.
    - `get(const Key)`: Recupera el valor asociado a una llave.
    - `full()`: Verifica si la tabla está llena.
    - `toString()`: Representa la tabla en formato texto para depuración.
  - Uso de un puntero a función como hash personalizado para permitir flexibilidad en la generación de índices.

- **Técnicas implementadas:**
  - **Resolución cuadrática:** Al manejar colisiones, utiliza una función de desplazamiento cuadrático para buscar una posición libre en la tabla.
  - **Gestión dinámica de memoria:** Reserva y libera memoria para llaves y valores.

### 2. **main.cpp**
Este archivo incluye un programa que prueba la funcionalidad de la clase `Quadratic`.

- **Hash personalizado:**
  - Función `myHash(const string)` que calcula el índice hash sumando los valores ASCII de los caracteres de una cadena.

- **Pruebas realizadas:**
  - Inserción de elementos en la tabla hash.
  - Verificación de la correcta ubicación de elementos.
  - Recuperación de valores asociados a llaves.
  - Comparación de resultados con salidas esperadas.

- **Salidas esperadas:**
  Las salidas se comparan con cadenas esperadas para verificar el correcto funcionamiento del programa.

## Uso

### Compilación
Para compilar el programa, utiliza un compilador de C++ compatible con plantillas, como `g++`:

```bash
g++ -o hash_table main.cpp
