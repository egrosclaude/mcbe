# MCBE: Modelo Computacional Binario Elemental
Scripts para trabajar con el Modelo Computacional Binario Elemental

----
- [Traductor mcbecc](#mcbecc)
  Traductor sub-C a ensamblador para la máquina MCBE
- [Ensamblador mcbeas](#mcbeas)
  Ensamblador e intérprete para la máquina MCBE
- [Máquina virtual mcbe](#mcbe)
  Ejecuta programas en código de máquina MCBE
- [Cómo usar los programas](#cómo-usar-los-programas)

[![asciicast](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5.png)](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5)

# mcbecc

Llamamos **Sub-C** a un subconjunto muy básico del lenguaje C, que nos sirve para ilustrar diferencias entre lenguajes de alto y bajo nivel, aspectos de la traducción de programas, diferencias entre compilación e interpretación, etc. 

El programa **mcbecc** es un **traductor** de Sub-C al lenguaje ensamblador, o assembler, de la máquina MCBE.

A continuación describimos el lenguaje Sub-C que es capaz de comprender el programa mcbecc.


## Lenguaje de entrada

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

Se proveen las sentencias de control if() y while(). No pueden anidarse.
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
int main()
{
	int a;
	int b;

	while(a != 10) {
		b = b + a;
		a++;
	}
	out(b);
}
```

### Comentarios

- Doble barra (//) al principio de una línea indica que la línea es de comentarios, y será ignorada por el traductor. El programador puede escribir lo que desee en los comentarios para documentar su programa.

# mcbeas

El programa **mcbeas** es un **ensamblador**, es decir, recibe como entrada un programa en lenguaje ensamblador, o assembler, del MCBE, y produce a la salida un programa en código de máquina. 

# mcbe

El programa **mcbe** es una **máquina virtual** MCBE, es decir, es un programa que emula el comportamiento que tendría una máquina MCBE si ésta fuera implementada.

# Cómo usar los programas

- Necesitamos una instalación de Linux (o el lenguaje Perl instalado en Windows). 
- Descargar https://github.com/egrosclaude/mcbe/archive/master.zip
- A partir de aquí todo funciona dentro del shell.
- unzip master.zip
- cd mcbe-master
- Seguir los ejemplos que se desarrollan en [la animación que aparece más arriba](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5). Esta animación se puede detener, reanudar, retroceder, etc.
- Intentar crear otros programas. ¡Ver qué pasa!

## ¡No tengo Linux!

¿No Linux? ¡No problem! La [máquina virtual Linux en Javascript](https://egrosclaude.github.io/IC2017/SistemasOperativos.html#/41) que hemos ofrecido como recurso de la materia cuenta con un intérprete de Perl que viene de lujo. Solamente hay que ser astuto y saber usar la función de subir archivos. 

Para usar estos programas en esa máquina virtual:

- Descargar https://github.com/egrosclaude/mcbe/archive/master.zip en nuestra máquina (no importa si no tenemos Linux)
- Descomprimir master.zip
- Ingresar a la [máquina virtual Linux](https://egrosclaude.github.io/IC2017/SistemasOperativos.html#/41)
- Pulsar el botón de **upload** o subir archivos que está junto a la cajita "Paste Here". No se ve bien debido al fondo negro, pero está ahí.
- Elegir los archivos mcbe, mcbecc y mcbeas de nuestro directorio mcbe-master y subirlos a la máquina virtual. El resto del trabajo se puede hacer dentro de la máquina virtual.
- Ponerles atributo de ejecutable a los tres programas con el comando ```chmod a+x mcbe*```.
- Opcionalmente también se pueden subir programas de ejemplo, pero son cortos y también se pueden tipear o editar con ```nano```.
- Como antes, seguir los ejemplos sugeridos en [la animación mencionada](https://asciinema.org/a/xiCBMssPwdwpeNlZTt0Mh3mF5). ¡Inventar algo!




