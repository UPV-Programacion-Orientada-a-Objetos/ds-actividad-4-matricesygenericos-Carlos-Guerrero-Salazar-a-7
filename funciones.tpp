#ifndef FUNCIONES_TPP
#define FUNCIONES_TPP

#include "campo2d.h"

// Constructor
template <typename T>
Campo2D<T>::Campo2D(int f, int c) : _datos(nullptr), _filas(f), _columnas(c) {
    _datos = new T*[_filas];
    for (int i = 0; i < _filas; ++i) {
        _datos[i] = new T[_columnas];
        for (int j = 0; j < _columnas; ++j) {
            _datos[i][j] = T();
        }
    }
}

// Destructor
template <typename T>
Campo2D<T>::~Campo2D() {
    if (_datos != nullptr) {
        for (int i = 0; i < _filas; ++i) {
            delete[] _datos[i];
        }
        delete[] _datos;
        _datos = nullptr;
    }
}

// Copia los valores de otro contructor
template <typename T>
Campo2D<T>::Campo2D(const Campo2D<T>& otro) : _datos(nullptr), _filas(otro._filas), _columnas(otro._columnas) {
    _datos = new T*[_filas];
    for (int i = 0; i < _filas; ++i) {
        _datos[i] = new T[_columnas];
        for (int j = 0; j < _columnas; ++j) {
            _datos[i][j] = otro._datos[i][j];
        }
    }
}

// cambia a una nueva matriz en base a otro
template <typename T>
Campo2D<T>& Campo2D<T>::operator=(const Campo2D<T>& otro) {
    if (this != &otro) {
        // Liberar memoria existente
        for (int i = 0; i < _filas; ++i) {
            delete[] _datos[i];
        }
        delete[] _datos;
        _filas = otro._filas;
        _columnas = otro._columnas;
        _datos = new T*[_filas];
        for (int i = 0; i < _filas; ++i) {
            _datos[i] = new T[_columnas];
            for (int j = 0; j < _columnas; ++j) {
                _datos[i][j] = otro._datos[i][j];
            }
        }
    }
    return *this;
}

// Redimensionar
template <typename T>
void Campo2D<T>::redimensionar(int nuevaF, int nuevaC) {
    T** temp = new T*[nuevaF];//creacion de una nueva matriz
    for (int i = 0; i < nuevaF; ++i) {
        temp[i] = new T[nuevaC];
        for (int j = 0; j < nuevaC; ++j) {
            temp[i][j] = T();
        }
    }
    int minF = (nuevaF < _filas) ? nuevaF : _filas;
    int minC = (nuevaC < _columnas) ? nuevaC : _columnas;
    
    for (int i = 0; i < minF; ++i) {
        for (int j = 0; j < minC; ++j) {
            temp[i][j] = _datos[i][j];
        }
    }
    for (int i = 0; i < _filas; ++i) {
        delete[] _datos[i];
    }
    delete[] _datos;
    _datos = temp;
    _filas = nuevaF;
    _columnas = nuevaC;
}

// Establecer valor
template <typename T>
void Campo2D<T>::setValor(int f, int c, T valor) {
    if (f >= 0 && f < _filas && c >= 0 && c < _columnas) {
        _datos[f][c] = valor;
    }
}

// Calcular Gradiente
template <typename T>
T Campo2D<T>::calcularGradientePromedio(int inicioF, int finF, int inicioC, int finC) {
    if (inicioF < 0 || finF > _filas || inicioC < 0 || finC > _columnas || inicioF >= finF || inicioC >= finC) {
        return T();
#include <iostream>
    }
    T suma = T();
    int contador = 0;
    for (int i = inicioF; i < finF; ++i) {
        for (int j = inicioC; j < finC; ++j) {
            // derecha
            if (j + 1 < finC) {
                T diferencia = _datos[i][j] - _datos[i][j + 1];
                suma += (diferencia < 0) ? -diferencia : diferencia;
                contador++;
            }
            
            // abajo
            if (i + 1 < finF) {
                T diferencia = _datos[i][j] - _datos[i + 1][j];
                suma += (diferencia < 0) ? -diferencia : diferencia;
                contador++;
            }
        }
    }
    return (contador > 0) ? suma / contador : T();
}

// Sobrecarga del operador []
template <typename T>
T* Campo2D<T>::operator[](int fila) {
    if (fila >= 0 && fila < _filas) {
        return _datos[fila];
    }
    return nullptr;
}

template <typename T>
const T* Campo2D<T>::operator[](int fila) const {
    if (fila >= 0 && fila < _filas) {
        return _datos[fila];
    }
    return nullptr;
}

#endif