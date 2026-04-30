Algoritmo GestionEstudiantes
    Definir opcion Como Entero
    Definir nombre, carrera Como Cadena
    Definir edad Como Entero
    Definir promedio Como Real
    
    Repetir
        Escribir "========================================"
        Escribir "   SISTEMA DE ARCHIVOS - UTA"
        Escribir "========================================"
        Escribir "1. Registrar estudiante"
        Escribir "2. Visualizar registros"
        Escribir "3. Salir"
        Escribir "Seleccione: "
        Leer opcion
        
        Segun opcion Hacer
            1:
                Escribir "--- REGISTRO DE ESTUDIANTE ---"
                Escribir "Nombre: "
                Leer nombre
                
                Repetir
                    Escribir "Edad: "
                    Leer edad
                    Si edad <= 0 Entonces
                        Escribir "Dato invalido. Ingrese una edad numerica."
                    FinSi
                Hasta Que edad > 0
                
                Escribir "Carrera: "
                Leer carrera
                
                Repetir
                    Escribir "Promedio (0-10): "
                    Leer promedio
                    Si promedio < 0 O promedio > 10 Entonces
                        Escribir "Dato invalido. Ingrese un promedio (0-10)."
                    FinSi
                Hasta Que promedio >= 0 Y promedio <= 10
                
                // Representación de la persistencia en PSeInt
                Escribir "Guardando en archivo: ", nombre, " | ", edad, " | ", carrera, " | ", promedio
                Escribir "Datos guardados correctamente."
                
            2:
                Escribir "--- LISTA DE ESTUDIANTES REGISTRADOS ---"
                // En PSeInt la lectura de archivos externos es simulada o limitada
                Escribir "Leyendo datos de estudiantes.txt..."
                Escribir "Nombre | Edad | Carrera | Promedio"
                
            3:
                Escribir "Cerrando sistema..."
                
            De Otro Modo:
                Escribir "Opcion incorrecta."
        FinSegun
        
    Hasta Que opcion = 3
    
FinAlgoritmo

