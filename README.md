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
  
