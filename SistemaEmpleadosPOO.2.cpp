#include <iostream>
#include <string>

/**
 * Clase: Empleado
 * Funcionalidad: Representa a un empleado con nombre y area de trabajo,
 *                controlando el acceso a sus datos mediante getters y setters.
 *                Sirve como clase base para permitir herencia y polimorfismo.
 * Entrada: N/A (declaracion de clase)
 * Salida: N/A (declaracion de clase)
 */
class Empleado
{
protected:
    std::string nombre;
    std::string area;

public:
    // Constructor
    Empleado(std::string nombre, std::string area);

    // Destructor virtual (buena practica cuando existe herencia)
    virtual ~Empleado() {}

    // Getters
    std::string getNombre() const;
    std::string getArea() const;

    // Setters
    void setNombre(std::string nuevoNombre);
    void setArea(std::string nuevaArea);

    // Metodo de utilidad, marcado como virtual para permitir sobrescritura
    virtual void mostrarInformacion() const;
};

/**
 * Funcionalidad: Construye un objeto Empleado inicializando su nombre y area.
 * Entrada: nombre (std::string), area (std::string)
 * Salida: N/A (constructor)
 */
Empleado::Empleado(std::string nombre, std::string area)
{
    this->nombre = nombre;
    this->area = area;
}

/**
 * Funcionalidad: Obtiene el nombre actual del empleado.
 * Entrada: Ninguna
 * Salida: std::string con el nombre del empleado
 */
std::string Empleado::getNombre() const
{
    return nombre;
}

/**
 * Funcionalidad: Obtiene el area actual del empleado.
 * Entrada: Ninguna
 * Salida: std::string con el area del empleado
 */
std::string Empleado::getArea() const
{
    return area;
}

/**
 * Funcionalidad: Actualiza el nombre del empleado.
 * Entrada: nuevoNombre (std::string)
 * Salida: Ninguna (modifica el atributo nombre)
 */
void Empleado::setNombre(std::string nuevoNombre)
{
    nombre = nuevoNombre;
}

/**
 * Funcionalidad: Actualiza el area del empleado.
 * Entrada: nuevaArea (std::string)
 * Salida: Ninguna (modifica el atributo area)
 */
void Empleado::setArea(std::string nuevaArea)
{
    area = nuevaArea;
}

/**
 * Funcionalidad: Imprime en consola el nombre y area del empleado.
 * Entrada: Ninguna
 * Salida: Ninguna (imprime en consola)
 */
void Empleado::mostrarInformacion() const
{
    std::cout << "Nombre: " << nombre << " | Area: " << area << std::endl;
}

/**
 * Clase: Gerente
 * Funcionalidad: Representa un empleado con responsabilidades adicionales
 *                de gestion. Hereda de Empleado (reutilizacion de codigo)
 *                y sobrescribe mostrarInformacion() para demostrar polimorfismo.
 * Entrada: N/A (declaracion de clase)
 * Salida: N/A (declaracion de clase)
 */
class Gerente : public Empleado
{
private:
    int cantidadPersonasACargo;

public:
    // Constructor
    Gerente(std::string nombre, std::string area, int cantidadPersonasACargo);

    // Getter propio de la clase derivada
    int getCantidadPersonasACargo() const;

    // Setter propio de la clase derivada
    void setCantidadPersonasACargo(int nuevaCantidad);

    // Sobrescritura (override) del metodo de la clase base
    void mostrarInformacion() const override;
};

/**
 * Funcionalidad: Construye un objeto Gerente. Reutiliza el constructor de
 *                Empleado para inicializar nombre y area, y ademas
 *                inicializa la cantidad de personas a cargo.
 * Entrada: nombre (std::string), area (std::string), cantidadPersonasACargo (int)
 * Salida: N/A (constructor)
 */
Gerente::Gerente(std::string nombre, std::string area, int cantidadPersonasACargo)
    : Empleado(nombre, area)
{
    this->cantidadPersonasACargo = cantidadPersonasACargo;
}

/**
 * Funcionalidad: Obtiene la cantidad de personas a cargo del gerente.
 * Entrada: Ninguna
 * Salida: int con la cantidad de personas a cargo
 */
int Gerente::getCantidadPersonasACargo() const
{
    return cantidadPersonasACargo;
}

/**
 * Funcionalidad: Actualiza la cantidad de personas a cargo del gerente.
 * Entrada: nuevaCantidad (int)
 * Salida: Ninguna (modifica el atributo cantidadPersonasACargo)
 */
void Gerente::setCantidadPersonasACargo(int nuevaCantidad)
{
    cantidadPersonasACargo = nuevaCantidad;
}

/**
 * Funcionalidad: Imprime en consola el nombre, area y cantidad de personas
 *                a cargo del gerente. Sobrescribe el comportamiento heredado
 *                de Empleado::mostrarInformacion() (polimorfismo).
 * Entrada: Ninguna
 * Salida: Ninguna (imprime en consola)
 */
void Gerente::mostrarInformacion() const
{
    std::cout << "Nombre: " << nombre << " | Area: " << area
        << " | Personas a cargo: " << cantidadPersonasACargo << std::endl;
}

/**
 * Funcionalidad: Punto de entrada del programa. Crea objetos Empleado y
 *                Gerente, demuestra encapsulamiento con getters/setters,
 *                y demuestra herencia y polimorfismo llamando
 *                mostrarInformacion() a traves de punteros a Empleado.
 * Entrada: Ninguna
 * Salida: int (codigo de salida del programa)
 */
int main()
{
    std::cout << "--- Creacion de objetos individuales ---" << std::endl;
    Empleado empleado1("Ana Rojas", "Recursos Humanos");
    Gerente gerente1("Luis Vargas", "Tecnologia", 5);

    empleado1.mostrarInformacion();
    gerente1.mostrarInformacion();

    empleado1.setArea("Finanzas");
    std::cout << "Area actualizada: " << empleado1.getArea() << std::endl;

    gerente1.setCantidadPersonasACargo(8);
    std::cout << "Personas a cargo actualizadas: "
        << gerente1.getCantidadPersonasACargo() << std::endl;

    std::cout << std::endl << "--- Demostracion de polimorfismo ---" << std::endl;

    // Abstraccion: se trabaja a traves de la interfaz publica de Empleado
    // (punteros a Empleado*), sin preocuparse por los detalles internos
    // de cada tipo concreto.
    Empleado* listaEmpleados[2];
    listaEmpleados[0] = &empleado1;
    listaEmpleados[1] = &gerente1;

    for (int i = 0; i < 2; i++)
    {
        // En tiempo de ejecucion se decide cual version de
        // mostrarInformacion() se ejecuta: la de Empleado o la de Gerente.
        listaEmpleados[i]->mostrarInformacion();
    }

    return 0;
}
