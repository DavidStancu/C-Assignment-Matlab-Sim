//Copyright David-Ioan Stancu 312CAb 2023-2024

my_octave.c

Pentru problema asta ma voi folosi de struct-ul matrix, 
pentru matricele incarcate in memorie, si struct-ul array 'list', ce reprezinta 
o lista a tuturor matricelor incarcate in memorie. De asemenea, 
ma voi folosi de o multitudine de alte functii, precum:

0. Functia de dublare a array-ului (arraysize_double):
    -de fiecare data cand o sa am nevoie sa dublez 'list'-ul,
    aceasta functie va fi apelata;

I. Functia de incarcare in memorie (matrix_loader):
    1. Creez o matrice noua, de care ma voi folosi pentru a incarca in memorie;
    2. Aloc memoria pentru matrice;
    3.1. Daca nu este loc in 'list' , apelez 'arraysize_double';
    3.2. Daca nu este nevoie, o adaug in 'list' si incrementez 'size';

II. Functia de determinare ale dimensiunilor unei matrice (matrix_dim):
    1. In matrix exista variabile care memoreaza numarul de linii si coloane pentru 
    fiecare matrice;
    2.1. Daca numarul introdus de la tastatura nu este valid(nu exista o matrice pe aceasta pozitie in array),
    se va afisa un mesaj de eroare si functia se va opri;
    2.2. Daca numarul introdus este valid, voi afisa numarul de linii si coloane memorate de matrix;

III. Functia de afisare a unei matrice (matrix_show):
    1.1. Daca pozitia nu este valida, voi afisa un mesaj de eroare;
    1.2. Voi afisa direct matricea memorata in 'list', de la pozitia ceruta;

IV. Functia de redimensionare a unei matrice (matrix_rearrange):
    1. Citesc doordonatele pentru remodelare a matricei, indiferent daca pozitia acesteia este valida sau nu;
    2. Memorez coordonatele in memorie prin doi vectori: newmatl(pentru linii), newmatc(pentru coloane);
    3.1. Daca matricea ceruta de tastatura nu exista(nu exista pe acea pozitie in array), se afiseaza un mesaj de eroare
    si se elibereaza memoria din newmatl si newmatc;
    3.2. Daca matricea exista pe o pozitie in 'list', se vor face modificarile conform coordonatelor;
    4. Noua matrice obtinuta va lua locul celei vechi;
    5. Se elibereaza memoria alocata newmatl si newmatc;

V. Functia de inmultire a doua matrici (matrix_multiply):
    1.1. Daca vreuna dintre cele doua coordonate ale matricilor nu sunt valide, se afeseaza un mesaj de eroare si
    se trece la urmatoarea comanda;
    1.2. Daca vreuna dintre cele doua matrici nu au dimensiunile corespunzatoare, se afiseaza un mesaj de eroare si
    se trece la urmatoarea comanda;
    1.3. Daca ambele coordonate sunt corecte, se va efectua inmultirea celor doua matrici;
    2. Matricea obtinuta se la afisa la sfarsitul array-ului;
    3. Daca este nevoie de mai mult spatiu in array, se va efectua arraysize_double;

VI. Functia de sortare (matrix_sort):
    1. Voi creea doua variabile, sum1 si sum2, in care voi memora suma matricilor, doua cate doua;
    2. Voi efectua sortarea matricilor din array doua cate doua prin metoda Selection Sort;

VII. Functia de transpunere a matricei (Matrix_flip):
    1.1. Daca numarul introdus de la tastatura nu este valid, se va afisa un mesaj de eroare si functia se va opri;
    1.2. Daca numarul introdus este corect, creez o a doua matrice in care voi memora matricea transpusa;
    2. Pentru a memora matricea transpusa, inlocuiesc variabilele de linii si coloane intre ele;
    3. Noua matrice la lua locul matricei originale;
    4. Eliberez memoria alocata matricii auxiliare;

VIII. Functia de ridicare a puterii (matrix_power):
    1.1. Daca numarul introdus de la tastatura nu este valid, se va afisa un mesaj de eroare si functia se va opri;
    1.2. Daca numarul introdus este corect, voi ridica la putere in mod exponential matricea;
    2. Noua matrica la lua locul precedentei;

IX. Functia de eliberare a memoriei unei matrici (matrix_free):
    1.1. Daca numarul introdus de la tastatura nu este valid, se va afisa un mesaj de eroare si functia se va opri;
    1.2. Daca numarul introdus este corect, voi elibera memoria din matricea ceruta;
    2. Se vor mota la stanga cu 1 restul matricilor existente dupa pozitia ceruta;

X. Functia de eliberare a memoriei din array (free_all);
    1. Eliberez memoria din intregul array si opresc programul;



