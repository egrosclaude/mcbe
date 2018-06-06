# MCBE: Modelo Computacional Binario Elemental
Programas para trabajar con el Modelo Computacional Binario Elemental

----
- [Máquina virtual mcbe](#mcbe)
  Ejecuta programas en código de máquina MCBE
- [Ensamblador mcbeas](#mcbeas)
  Ensamblador e intérprete para la máquina MCBE
- [Traductor mcbecc](#mcbecc)
  Traductor sub-C a ensamblador para la máquina MCBE
- [Cómo usar los programas](#cómo-usar-los-programas)
  - [Instalación en Linux](#instalación-en-linux)
  - [¡No tengo Linux!](#no-tengo-linux)
  - [Uso de los programas en línea de comandos](#uso-de-los-programas-en-línea-de-comandos)
- [Sub-C](#sub-c)
  Subconjunto restringido del lenguaje C

# Qué es el Modelo Computacional Binario Elemental
Es una máquina de programa almacenado, **teórica y minimalista**, que cuenta con una CPU, una memoria y órganos de entrada/salida. Su finalidad es introducir a temas de Organización y Arquitectura de Computadoras para alumnos de primer año de Licenciaturas en Ciencias de la Computación y afines, de la Universidad Nacional del Comahue. Forma parte del material didáctico de la asignatura [Introducción a la Computación](http://pedco.uncoma.edu.ar/course/view.php?id=1553).

Una descripción completa del MCBE puede estudiarse en el [material de dicha asignatura](https://egrosclaude.github.io/IC2017/ArquitecturaDeComputadoras.html).


# Un video de cómo trabajar

[![asciicast](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5.png)](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5)

# Los programas
## mcbe

El programa **mcbe** es una **máquina virtual** MCBE, es decir, es un programa que emula el comportamiento que tendría una máquina MCBE si ésta fuera implementada.

## mcbeas

El programa **mcbeas** es un **ensamblador**, es decir, recibe como entrada un programa en lenguaje ensamblador, o assembler, del MCBE, y produce a la salida un programa en código de máquina. 

## mcbecc

El programa **mcbecc** es un **traductor** de Sub-C (un subconjunto de C) al lenguaje ensamblador, o assembler, de la máquina MCBE.

----

# Cómo usar los programas
## Instalación en Linux

- Necesitamos una instalación de Linux (o el lenguaje Perl instalado en Windows). 
- Descargar https://github.com/egrosclaude/mcbe/archive/master.zip
- A partir de aquí todo funciona dentro del shell.
- unzip master.zip
- cd mcbe-master
- Seguir los ejemplos que se desarrollan en [la animación que aparece más arriba](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5). Esta animación se puede detener, reanudar, retroceder, etc.
- Intentar crear otros programas. ¡Ver qué pasa!

## ¡No tengo Linux!

¿No Linux? ¡No problem! La [máquina virtual Linux en Javascript](https://egrosclaude.github.io/IC2017/SistemasOperativos.html#/41) que hemos ofrecido como recurso de la materia cuenta con un intérprete de Perl que viene de lujo. Solamente hay que ser astutos y saber usar la función de subir archivos. 

Para usar estos programas en esa máquina virtual:

- Descargar https://github.com/egrosclaude/mcbe/archive/master.zip en nuestra máquina.
- Descomprimir master.zip.
- Ingresar a la [máquina virtual Linux](https://egrosclaude.github.io/IC2017/SistemasOperativos.html#/41).
- Pulsar el botón de **upload** o subir archivos que está junto a la cajita "Paste Here". No se ve bien debido al fondo negro, pero está ahí.
- Elegir los archivos mcbe, mcbecc y mcbeas de nuestro directorio mcbe-master y subirlos a la máquina virtual. El resto del trabajo se puede hacer dentro de la máquina virtual.
- Ponerles atributo de ejecutable a los tres programas con el comando ```chmod a+x mcbe*```.
- Opcionalmente también se pueden subir los programas de ejemplo, pero como son muy cortos también se pueden tipear (con ```cat > archivo``` o editar (con ```nano archivo```).
- Como antes, seguir los ejemplos sugeridos en [la animación mencionada](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5).

## Uso de los programas en línea de comandos

### Para traducir un programa en C a ensamblador
- El comando ```./mcbecc prog.c``` mostrará por pantalla los mnemónicos de ensamblador MCBE equivalentes al programa en C. 
- El comando ```./mcbecc prog.c > prog.asm``` guardará esos mismos mnemónicos en un archivo llamado prog.asm

![mcbecc.svg](/img/mcbecc.svg)

### Para generar código ejecutable para MCBE a partir de ensamblador
- El comando ```./mcbeas -g prog.asm``` mostrará por pantalla los códigos de instrucciones MCBE equivalentes al programa en ensamblador.
- El comando ```./mcbeas -g prog.asm > prog.exe``` guardará esos mismos códigos de instrucciones en un archivo llamado prog.exe.

![mcbeas.svg](/img/mcbeas.svg)

### Para ejecutar un programa en la máquina virtual MCBE
- El comando ```./mcbe prog.exe``` ejecutará el programa prog.exe. 
- Si el cursor se detiene sin imprimir nada, es posible que la máquina virtual esté ejecutando una operación LD IN (entrada de usuario), por lo cual el usuario debe introducir un dato en decimal.
- Si el programa emite información por la salida (instrucción ST OUT), es posible que se desee imprimir esa información en diferentes formatos. Las opciones -A, -H y -B hacen que la salida se vea en formato ASCII, hexadecimal y binario, respectivamente.

![mcbe.svg](/img/mcbe.svg)

### Para ensamblar un programa en ensamblador
- El comando ```./mcbeas -a prog.asm``` mostrará por pantalla los códigos de instrucciones equivalentes a los mnemónicos pero en formato de números binarios.
- El comando ```./mcbeas -a -v prog.asm``` mostrará por pantalla la misma lista pero con mnemónicos y números de línea.

### Para interpretar un programa en ensamblador
- El comando ```./mcbeas -i -v prog.asm``` interpretará el programa en ensamblador, mostrando a cada paso el estado de la máquina con sus registros y memoria.

### Para encadenar operaciones
- En ciertas condiciones (\*) es posible realizar más de un paso de los anteriores en forma encadenada gracias a la capacidad de **entubamiento** o **pipelining** del shell de Linux. 
    - El símbolo para indicar entubamiento de comandos es **|** (que suele leerse "pipe"). En el comando ```ls | more```, por ejemplo, este símbolo dice que la salida del comando ls (la lista de nombres y atributos de los archivos) sea introducida como entrada del comando ```more``` (paginar). De esta manera, cuando la lista de archivos es muy larga, la vemos paginada.
- Nuestros programas para trabajar con MCBE generan salida que sirve como entrada para los otros programas. El programa mcbecc genera assembler que tomará mcbeas, y mcbeas genera código ejecutable que tomará mcbe.
- Así, podemos encadenar la traducción, el ensamblado y la ejecución, todo en un solo comando:
```./mcbecc prog.c | ./mcbeas -g - | ./mcbe - ```. El símbolo **-** significa que la entrada de los comandos mcbeas y mcbe no debe ser tomada de un archivo sino de la tubería.
- Como en este caso la entrada está siendo tomada de la tubería, el programa mcbe no puede recibir entrada de usuario, que está operando el teclado. Las condiciones (\*) son que los programas no pidan entrada de usuario.

----

## Sub-C

Llamamos **Sub-C** a un subconjunto muy básico del lenguaje C, que nos sirve para ilustrar diferencias entre lenguajes de alto y bajo nivel, aspectos de la traducción de programas, diferencias entre compilación e interpretación, etc. 

A continuación describimos el lenguaje Sub-C que es capaz de comprender el programa mcbecc.


### Programa

- Constituido por una única función, main()
- Sentencias terminadas por punto y coma

```
int main()
{
   ...sentencias...
}
```


### Constantes
- Únicamente constantes enteras en formato decimal

### Variables

- Variables enteras 
- Deben estar declaradas 
- Sus nombres pueden contener dígitos pero deben comenzar por una letra
- Opcionalmente, inicializadas en la declaración
- Constantes y variables son almacenadas en 8 bits en complemento a 2

```
int main()
{
   int a;
   int b = 1;
   int cad2;
   int d8;
}
```

### Asignaciones

- Asignación de constantes a variables
- Asignación de variables a variables

```
int main()
{
   int a;
   int b = 1;
   
   a = 2;
   b = a;
}
```


### Operaciones aritméticas

- Sumas y restas entre exactamente dos operandos
- Los operandos pueden ser variables o constantes
- Únicamente pueden aparecer como miembro derecho de una asignación

```
int main()
{
   int a;
   int b = 1;
   int c;
   
   a = 2;
   b = a + 3;
   a = 2 + b;
   c = a + b;
}
```

#### Acumulador

- Cuando las mismas variables aparecen en ambos miembros de la asignación se obtiene una construcción de "acumulador"

```
int main()
{
   int b = 1;
   
   b = b + 3;
}
```
#### Operador de autoincremento y autodecremento

- Una variable puede incrementar o decrementar en 1 su valor con la sintaxis siguiente

```
int main()
{
   int b = 1;
   int c;
   c = 6;
   b++; // b queda con valor 2
   c--; // c queda con valor 5
}
```
## Entrada y salida

- Dos funciones de E/S de bytes, in() y out().
- Una función de E/S de strings, printf().

La función de entrada in() recibe como argumento la dirección de una variable. Espera el ingreso de un número a cargo del usuario.
```
int main()
{
   int b = 1;

   in(&b);
}
```

La función de salida out() recibe como argumento la variable cuyo contenido se desea imprimir.

```
int main()
{
   int b = 1;

   out(b);
}
```
La función de salida printf() recibe como argumento un string. No hace conversiones. Es equivalente a un lazo formado por llamadas a out().

```
int main()
{
   printf("Hola Mundo!");
}
```

## Sentencias de control

Se proveen las sentencias de control if() y while(). 
- Las condiciones de control para ambas construcciones pueden ser:
    - La comparación por diferencia (!=) entre una variable y una constante.
    - La comparación por diferencia (!=) entre dos variables.

### Sentencia if()

- Permite decidir entre dos alternativas.

```
int main()
{
	int a;

	in(&a);
	if(a != 10) {
		a = a + 1;
	}
	out(a);
}
```


### Sentencia while()

- Permite iterar un conjunto de sentencias mientras una condición sea verdadera.


```
// Calcula e imprime la suma de 1 a 10
int main()
{
	int a = 1;
	int b = 0;

	while(a != 11) {
		b = b + a;
		a++;
	}
	out(b);
}
```
### Anidamiento de sentencias de control

Las sentencias de control pueden anidarse, pero es muy probable que la traducción a ensamblador produzca programas que ocupen más memoria de la disponible (en MCBE, solamente se pueden ocupar las posiciones 0 a 29) o que tengan saltos con desplazamiento mayor del permitido (en MCBE, el rango de desplazamiento para los saltos relativos es \[-16, 15]).

Una **posible** solución es optimizar a mano el código assembler producido.

```
// Pide tres datos y los imprime, 
// excepto que el dato sea 0
int main()
{
	int a = 0;
	int b;

	while(a != 3) {
		in(&b);
		if(b != 0) {
			out(b);
		}
		a++;
	}
}
```

### Comentarios

- Doble barra (//) al principio de una línea indica que la línea es de comentarios, y será ignorada por el traductor. El programador puede escribir lo que desee en los comentarios para documentar su programa.





