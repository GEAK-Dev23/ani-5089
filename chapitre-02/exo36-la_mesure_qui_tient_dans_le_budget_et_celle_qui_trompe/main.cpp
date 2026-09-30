#include <iostream>
#include <string>

int main()
{
    long long budget = 0;
    int s = 0;
    if (!(std::cin >> budget >> s)) {
        std::cout << "TROMPE 0\n";
        return 0;
    }

    int trompe = 0;
    for (int i = 0; i < s; ++i) {
        std::string nom;
        long long debug = 0;
        long long release = 0;
        if (!(std::cin >> nom >> debug >> release)) {
            break;
        }

        // Facteur arrondi a l'entier le plus proche, calcule en entiers
        long long facteur = 0;
        if (release != 0) {
            facteur = (debug + release / 2) / release;
        }

        bool tient = release <= budget;
        if (tient && debug > budget) {
            ++trompe;
        }

        std::cout << nom << ' ' << facteur << ' ' << (tient ? "TIENT" : "DEPASSE") << '\n';
    }

    std::cout << "TROMPE " << trompe << '\n';

    return 0;
}
