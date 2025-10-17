#ifndef CAMPO2D_H
#define CAMPO2D_H

template <typename T>
class Campo2D {
private:
    T **_datos;
    int _filas;
    int _columnas;

public:
    Campo2D(int f, int c);//constructor
    ~Campo2D();//destructor

    Campo2D(const Campo2D<T>& otro);//constructor de copia
    Campo2D<T>& operator=(const Campo2D<T>& otro);//cambio de datos
    void redimensionar(int nuevaF, int nuevaC);//redimensionar matriz
    void setValor(int f, int c, T valor);//establece valores
    T calcularGradientePromedio(int inicioF, int finF, int inicioC, int finC);
    T* operator[](int fila);//sobrecarga del operador []
    const T* operator[](int fila) const;//sobrecarga del operador [] constante
    int getFilas() const { return _filas; }
    int getColumnas() const { return _columnas; }
    T getValor(int f, int c) const { return _datos[f][c]; }
};

#include "funciones.tpp"
#endif