#include <iostream>
#include "campo2d.h"

int main() {
    std::cout << "--- Simulador Genérico de Campo 2D ---\n" << std::endl;
    
    // Test con FLOAT
    std::cout << ">> Inicializando Campo Gravitatorio (Tipo FLOAT) <<" << std::endl;
    std::cout << "Creando Grid (FLOAT) de 3x3..." << std::endl;
    
    Campo2D<float> matriz(3, 3);
    
    std::cout << "Estableciendo valores iniciales...\n" << std::endl;
    matriz.setValor(0, 0, 10.1);
    matriz.setValor(0, 1, 8.0);
    matriz.setValor(0, 2, 5.0);
    matriz.setValor(1, 0, 12.0);
    matriz.setValor(1, 1, 9.0);
    matriz.setValor(1, 2, 6.0);
    matriz.setValor(2, 0, 15.0);
    matriz.setValor(2, 1, 11.0);
    matriz.setValor(2, 2, 7.3);

    std::cout << "Pasandolos a la matriz especifica..."<<std::endl;
    Campo2D<float> matrizfloat = matriz; // Usando el constructor de copia
    std::cout << "Matriz copiada exitosamente.\n" << std::endl;
    std::cout << "Grid Actual (Paso 0):" << std::endl;
    for (int i = 0; i < matrizfloat.getFilas(); ++i) {
        std::cout << "| ";
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            std::cout<< matrizfloat[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Opción: Calcular Gradiente Promedio" << std::endl;
    std::cout << "Ingrese Fila Inicial: 0, Fila Final: 2" << std::endl;
    std::cout << "Ingrese Columna Inicial: 0, Columna Final: 2\n" << std::endl;
    
    std::cout << "Calculando Gradiente Promedio en la región [0,2]x[0,2]..." << std::endl;
    float gradiente = matrizfloat.calcularGradientePromedio(0, 2, 0, 2);
    std::cout << "Gradiente Promedio calculado: " << gradiente << " unidades/metro.\n" << std::endl;
    
    std::cout << "Opción: Redimensionar" << std::endl;
    std::cout << "Redimensionando Grid a 4x4..." << std::endl;
    matriz.redimensionar(4, 4);
    std::cout << "Datos copiados. Memoria antigua liberada.\n" << std::endl;
    
    std::cout << "Opción: Redimensionar (A una dimensión menor)" << std::endl;
    std::cout << "Redimensionando Grid a 2x2..." << std::endl;
    matriz.redimensionar(2, 2);
    std::cout << "Datos copiados. Memoria antigua liberada.\n" << std::endl;
    
    // Test con INT
    std::cout << ">> Test con INT <<" << std::endl;
    Campo2D<int> matrizInt(3, 3);
    matrizInt[0][0] = 5;
    matrizInt[0][1] = 10;
    matrizInt[1][0] = 8;
    matrizInt[1][1] = 12;
    std::cout << "Grid Actual (INT):" << std::endl;
    for (int i = 0; i < matrizInt.getFilas(); ++i) {
        std::cout << "| ";
        for (int j = 0; j < matrizInt.getColumnas(); ++j) {
            std::cout << matrizInt[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "Usando operador: matrizInt[0][0] = " << matrizInt[0][0] <<"y getvalor(0,0): " << matrizInt.getValor(0,0) <<"\n" << std::endl;
    
    std::cout << ">> Test con DOUBLE <<" << std::endl;
    Campo2D<double> matrizDouble(2, 2);
    matrizDouble.setValor(0, 0, 3.14);
    matrizDouble.setValor(0, 1, 2.71);
    matrizDouble.setValor(1, 0, 1.41);
    matrizDouble.setValor(1, 1, 1.73);
    std::cout << "Grid Actual (DOUBLE):" << std::endl;
    for (int i = 0; i < matrizDouble.getFilas(); ++i) {
        std::cout << "| ";
        for (int j = 0; j < matrizDouble.getColumnas(); ++j) {
            std::cout << matrizDouble[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    
    double gradienteD = matrizDouble.calcularGradientePromedio(0, 2, 0, 2);
    std::cout << "Gradiente Promedio (DOUBLE): " << gradienteD << "\n" << std::endl;
    
    std::cout << "Opción: Salir" << std::endl;
    std::cout << "Destructor invocado. Liberando memoria de la Matriz 2D..." << std::endl;
    std::cout << "Sistema cerrado." << std::endl;
    
    return 0;
}