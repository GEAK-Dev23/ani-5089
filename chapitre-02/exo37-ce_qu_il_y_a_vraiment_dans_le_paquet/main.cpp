#include <iostream>
#include <string>

static bool commencePar(const std::string& texte, const std::string& debut)
{
    return texte.size() >= debut.size() && texte.compare(0, debut.size(), debut) == 0;
}

static bool finitPar(const std::string& texte, const std::string& fin)
{
    return texte.size() >= fin.size()
        && texte.compare(texte.size() - fin.size(), fin.size(), fin) == 0;
}

int main()
{
    std::string architecture;
    int f = 0;
    std::cin >> architecture >> f;

    // Le segment entier, barre oblique comprise : armeabi-v7a ne passe pas pour arm64-v8a
    const std::string dossierVoulu = "lib/" + architecture + "/";

    long long total = 0;
    bool signe = false;
    bool abi = false;
    int inutiles = 0;

    for (int i = 0; i < f; ++i) {
        std::string chemin;
        long long taille = 0;
        if (!(std::cin >> chemin >> taille)) {
            break;
        }

        total += taille;

        if (commencePar(chemin, "META-INF/")
            && (finitPar(chemin, ".RSA") || finitPar(chemin, ".DSA") || finitPar(chemin, ".EC"))) {
            signe = true;
        }

        if (commencePar(chemin, "lib/")) {
            if (commencePar(chemin, dossierVoulu)) {
                abi = true;
            } else {
                ++inutiles;
            }
        }
    }

    std::cout << total << '\n';
    std::cout << (signe ? "SIGNE" : "NON SIGNE") << '\n';
    std::cout << (abi ? "ABI OUI" : "ABI NON") << '\n';
    std::cout << "INUTILE " << inutiles << '\n';

    return 0;
}
