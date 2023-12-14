# Examen-Tema-2

## Parte 1: Preguntas de elección múltiple (20%)
**1. ¿Cuál es la principal diferencia entre la estructura básica del programa en C y C++?**
b) C utiliza printf y scanf mientras que C++ utiliza std::cout y std::cin.

**2. ¿Qué es un espacio de nombres en C++?**
a) Una característica que permite agrupar entidades como clases, objetos y funciones bajo un nombre.

**3. En programación orientada a objetos en C++, ¿qué es una clase?**
d) Una plantilla para crear objetos, proporciona una definición inicial para el estado (miembros de datos) y el comportamiento (miembros de la función).
con punteros
**4. ¿Qué son los templates en C++?**
b) Permiten la creación de funciones y clases genéricas, es decir, que pueden trabajar con cualquier tipo de datos.

## Parte 2: Pregunta de desarrollo de código (80%)
**Estructura del Estudiante:**
*Discute las diferencias clave entre las dos implementaciones*
En el código de c++ se usa el std::string para el nombre, lo que da mayor flexibilidad y gestión de la memoria. En c utilizo un arreglo de caracteres que es menos flexible. Respecto a la sintaxis de impresión en C++ uso std::cout para imprimiry en C uso printf para la impresión. En la sintaxis del main se omite return 0; y es más flexible en c++, y en c se usa el return 0 al final. En la gestion de la memoria en c++ el std::string maneja la gestión de memoria automáticamente y en se manejao manualmente la memoria.

**Manejo de Excepciones:**
*Aunque C no tiene un sistema integrado de manejo de excepciones como C++, discute cómo podrías manejar errores y situaciones inesperadas en este lenguaje.*
como puedes apreciar he integrado algunas recomendaciones externas para el manejo de expeciones en c, buscando diferentes alternativas como las que ofrece c++ he considerado integrar algun codigo de retrono, que indica el estado de la funcin, variables globales para los errores, que almacenan la informacion de los errores para no cometerlos y evitarlos, y por último, ya que da información adicional de los errores.

**Conclusión:**
*¿Cuál de los dos lenguajes consideras más adecuado para el proyecto del CGEA?*
En general cada lenguaje tiene unos aspectos mas favorables para usar a la hora de mostrar la informacion de los estudiantes de manera mas eficiente, en mi opinion el que considero más adecuado para el proyecto del CGEA es C++, basandome en mi integración de ambos, he podido apreciar que el lenguaje de C++ es más completo y orgaizado por la orinetación de objetos, ofrece mayor claridad y eficiencia en el codigo, además el manejo de errores es mucho mejor en c++ debido a que se puede integrar manejos de errores en c pero no es del todo recomendable en algunos aspectos.

*¿Qué recomendaciones harías al equipo de desarrollo del CGEA para la siguiente fase del proyecto?*
La recomdanción que yo le daría al equipo del CGEA en base a mi implementación de la primera fase del proyecto es integrar el lenguaje de C++ o buscar otros lenguajes para integrar mejores manejos de errores y seguridad al ser una red muy grande y que necesita mucha seguridad para almacenar todos los datos, recomandaria un lenguaje mas moderno como Python, que es más seguro y recomendable para estos casos.
