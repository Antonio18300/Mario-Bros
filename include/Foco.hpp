#include <stdexcept>
class Foco
{
private:
    int numero;
    bool encendido;

public:
    Foco()
    {
        this->numero = 0;
        this->encendido = false; // sin parametros
    }
    Foco(int numero)
    {
        this->encendido = false; // con parametros
        if (numero > 100 || numero < 0)
        {
            throw new std ::runtime_error("NUMERO FUERA DE RANGO");
        }
        else
        {
            this->numero = numero;
        }
    }
    ~Foco() {}
    void Incrementar(int numero)
    {
        this->numero += numero;
    }
    void Disminuir(int numero)
    {
        this->numero -= numero;
    }

    Foco operator+(Foco p1)
    {
        return this->numero + p1.numero;
    }

    void Encender()
    {
        this->encendido = true;
    }
    void Apagar()
    {
        this->encendido = false;
    }

    // sobrecargar operador doble flecha, ostream es un flujo
    char imprimir()
    {
        if (this->encendido)
        {
            return '*';
        }
        else
        {
            return 'o';
        }

        return this->encendido;
    }
};