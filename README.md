# Simulation of the Car Overtaking Process

## Description
Our project simulates the overtaking process between two cars on a single lane of traffic. It tracks the movement and interaction between two cars, taking into account varying speeds and the need for safe overtaking.

## Programming Languages Used
- **C++**: For the basic logic and simulation of the overtaking process.
- **OpenGL (GLUT)**: For the graphical interface and visualization of the process.

## Dependencies
The project requires the installation of the OpenGL library and GLUT. These allow the application to run and provide the graphical visualization of the simulation.

## Steps For Running The Project
1. **Installing Dependencies**: Ensure you have the OpenGL and GLUT libraries installed on your system.
2. **Compiling the Code**: Use a compatible C++ compiler to compile the source code. The source code is located in the `tema.cpp` file. If you do not have access to Visual Studio 2019, you can use another compatible compiler. For example, using `g++`:
 ```bash g++ -o simulareDepasire main.cpp -lGL -lGLU -lglut ```
3. **Running the Application**: After compiling, you can run the created executable:
    ./simulareDepasire
4. **Testing the Project**: To test the project, watch the graphic window that opens after running. You should see two cars: a blue one and a red one. The red car will attempt to overtake the blue car, performing the overtaking maneuver based on their relative speeds and positions.

### Romanian Translation Below
---


# Simularea Procesului de Depășire a unei Mașini

## Descriere
Proiectul nostru simulează procesul de depășire între două mașini pe o singură bandă de circulație. Acesta urmărește mișcarea și interacțiunea dintre două mașini, luând în considerare vitezele variabile și necesitatea depășirii în condiții de siguranță.

## Limbaje de Programare Utilizate
- **C++**: Pentru logica de bază și simularea procesului de depășire.
- **OpenGL (GLUT)**: Pentru interfața grafică și vizualizarea procesului.

## Dependințe
Proiectul necesită instalarea bibliotecii OpenGL și a GLUT. Acestea permit rularea aplicației și vizualizarea grafică a simulării.

## Pași Pentru Rularea Proiectului
1. **Instalarea Dependințelor**: Asigurați-vă că aveți instalate bibliotecile OpenGL și GLUT pe sistemul dvs.
2. **Compilarea Codului**: Utilizați un compilator C++ compatibil pentru a compila codul sursă. Codul sursă se află în fișierul `tema.cpp`. Dacă nu aveți acces la Visual Studio 2019, puteți folosi un alt compilator compatibil. De exemplu, folosind `g++`:
   ```bash g++ -o simulareDepasire main.cpp -lGL -lGLU -lglut ```
3. **Rularea Aplicației**: După compilare, puteți rula executabilul creat:
     ./simulareDepasire
4. **Testarea Proiectului**: Pentru a testa proiectul, urmăriți fereastra grafică care se deschide după rulare. Ar trebui să observați două mașini: una albastră și una roșie. Mașina roșie va încerca să depășească mașina albastră, executând manevra de depășire în funcție de vitezele relative și pozițiile mașinilor.
  
