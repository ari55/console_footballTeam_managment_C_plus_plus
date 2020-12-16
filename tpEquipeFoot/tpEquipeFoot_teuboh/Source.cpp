#include <iostream>
using namespace std;

const unsigned short TAILLE_NOM = 31;
const unsigned short TAILLE_PRENOM = 31;
const unsigned short NUMERO_MIN = 0;
const unsigned short NUMERO_MAX = 100;
const unsigned short CHOIX_MAX = 10;


char chaine[31];


enum Position {
	GARDIEN_DE_BUT = 1,
	ATTAQUANT,
	DEFENSEUR,
	MILIEU_DE_TERRAIN
};

struct joueur {
	unsigned short noDeJoueur;
	char nom[TAILLE_NOM];
	char prenom[TAILLE_PRENOM];
	unsigned short nbButs;
	Position position;
};
enum Menu {
	AjouterUnJouer = 1,
	modifierUnJoueur,
	retirerUnJoueur,
	RECHERCHER_JOUEUR,
	AFFICHER_INFO_JOUEUR,
	AJOUTER_BUT,
	retirerButJoueurSelonNumJoueur,
	afficherJoueurParPosition,
	AfficherTotalButEquipe,
	Quitter
};
enum ChoixAffichage {
	AFFICHER_TOUS = 1,
	AFFICHER_PAR_POSITION
};
int monMenu();
int validerNumerique();
void validerChaine(char chaine[], const int TAILLE);
unsigned short validerEntierEntreIntervalle(const int NUM_MIN, const int NUM_MAX);
joueur creerUnJoueur(joueur joueurs[], const int TAILLE);
void afficherMenu(joueur joueurs[], unsigned short nbJoueurs);
void ajouterJoueur(joueur joueurs[], unsigned short& nbJoueurs, const int TAILLE);
int rechercheLineaire(joueur joueurs[], const int TAILLE, int valeurRecherchee);
void afficherTousLesJoueurs(joueur joueurs[], unsigned short& nbJoueurs);
int rechercherJoueur(joueur joueurs[], const int TAILLE, unsigned short nbJoueurs);
void modifierJoueur(joueur joueurs[], const int TAILLE, joueur& joueur);
void retirerJoueur(joueur joueurs[], const int TAILLE, unsigned short& nbJoueurs);
void afficherInfoJoueur(const joueur& JOUEUR, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs);
void ajouterButJoueur(joueur& leJoueur, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs);
void retirerButJoueur(joueur& leJoueur, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs);
void afficherJoueursParPosition(joueur joueurs[], const int TAILLE, unsigned short nbJoueurs);
void afficherTotalDeButDeLEquipe(joueur joueurs[], unsigned short& nbJoueurs);

int main() {
	locale::global(locale(""));
	const int TAILLE = 1000;
	joueur joueurs[TAILLE];
	unsigned short nbJoueurs = 0;
	//À compléter
	afficherMenu(joueurs, nbJoueurs);

	system("pause");
	return 0;
}

/*
	Tâche : fonction qui fait apparaitre un menu, demande de faire un
			choix à l'utilisateur, récupère ce choix et le retourne.
	Paramètre(s) : aucun
	Retour : Le choix effectué par l'utilisateur
*/
void afficherMenu(joueur joueurs[], unsigned short nbJoueurs) {
	//À compléter
	//return 0; // À remplacer car c'est seulement là pour que le code compile*/
	short int choix;
	const int TAILLE = 14;
	joueur joueur;
	nbJoueurs = 0;
	do {
		choix = monMenu();
		switch (choix)

		{
		case (Menu::AjouterUnJouer):
			system("CLS");
			ajouterJoueur(joueurs, nbJoueurs, TAILLE);
			cout << "le joueur a ete ajoute" << endl;

			break;
		case (Menu::modifierUnJoueur):
			system("CLS");
			modifierJoueur(joueurs, TAILLE, joueur);
			break;
		case (Menu::retirerUnJoueur):
			system("CLS");
			retirerJoueur(joueurs, TAILLE, nbJoueurs);
			//afficherTousLesJoueurs(joueurs);

			break;
		case (Menu::RECHERCHER_JOUEUR):
			rechercherJoueur(joueurs, TAILLE, nbJoueurs);
			system("pause");
			system("CLS");
			break;
		case (Menu::AFFICHER_INFO_JOUEUR):
			afficherInfoJoueur(joueur, joueurs, TAILLE, nbJoueurs);
			system("pause");
			system("CLS");
			break;

		case (Menu::AJOUTER_BUT):
			ajouterButJoueur(joueur, joueurs, TAILLE, nbJoueurs);
			system("pause");
			system("cls");
			break;
		case (Menu::retirerButJoueurSelonNumJoueur):
			retirerButJoueur(joueur, joueurs, TAILLE, nbJoueurs);
			system("pause");
			system("cls");
			break;

		case (Menu::afficherJoueurParPosition):
			//afficherTousLesJoueurs(joueurs, nbJoueurs);
			afficherJoueursParPosition(joueurs, TAILLE, nbJoueurs);
			system("pause");
			system("cls");
			break;
		case (Menu::AfficherTotalButEquipe):
			afficherTotalDeButDeLEquipe(joueurs, nbJoueurs);
			break;
		}

	} while (choix != Menu::Quitter);

}

int monMenu()
{
	int resultat = 0;
	cout << endl << " ----------------------- MENU -----------------------" << endl << endl;
	cout << " Bienvenue " << endl;
	cout << "<1>  Ajouter un joueur. " << endl;
	cout << "<2>  Modifier un joueur." << endl;
	cout << "<3>  Retirer un joueur. " << endl;
	cout << "<4>  Rechercher un joueurs " << endl;
	cout << "<5>  Afficher les informations d'un joueur " << endl;
	cout << "<6>  Ajouter un but à un joueur . " << endl;
	cout << "<7>  Retirer un but à un joueur . " << endl;
	cout << "<8>  Afficher les joueurs par position" << endl;
	cout << "<9>  Afficher  le total but de l'equipe" << endl;
	cout << "<10>  Quitter  l'application " << endl;
	cout << "CHOIX :  " << endl;
	//cin >> resultat;
	resultat = validerEntierEntreIntervalle(NUMERO_MIN, CHOIX_MAX);

	return resultat;

}


/*
	Tâche : fonction qui sert à insérer UN SEUL nouveau joueur dans l'équipe. Demander une saisie pour chacune des informations d’un joueur, sauf pour le nombre de but, qui sera initialisé à 0 au moment de la création.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (sortie via les paramètres formels passés par adresse et/ou référence)
*/
void ajouterJoueur(joueur joueurs[], unsigned short& nbJoueurs, const int TAILLE) {
	//À compléter
	//unsigned short* pteur;
	//pteur = &nbJoueurs;
	joueur j;
	j = creerUnJoueur(joueurs, TAILLE);
	joueurs[nbJoueurs] = j;
	nbJoueurs++;
	//cout << nbJoueurs;
}

joueur creerUnJoueur(joueur joueurs[], const int TAILLE) {
	joueur j;
	unsigned short numero;
	bool existe = true;
	//j.noDeJoueur = (nbJoueurs + NUMERO_BASE);//demander la saisie dun numero de joueur et valider si le numero ne se trouve pas deja ;
	j.nbButs = 0;

	cout << "                                  Creation d'un nouveau joueur" << endl;
	//cout << "saisir le numero du joueur" << endl;
	cout << "Veuillez saisir le nom du joueuer : " << endl;
	// cin.getline(j.nom, 31);
	validerChaine(j.nom, 31);
	cout << "Veuillez saisir le prenom du joueuer : " << endl;
	validerChaine(j.prenom, 31);
	/////
	do {
		cout << "saisir le numero de joueur a ajouter (numero entre 1 et 100) " << endl;
		numero = validerEntierEntreIntervalle(NUMERO_MIN, NUMERO_MAX);
		int indiceTrouve = rechercheLineaire(joueurs, TAILLE, numero);
		if (!(indiceTrouve != -1)) {
			j.noDeJoueur = numero;
			existe = false;
		}
		else {
			cout << "le joueur numero " << numero << "  se trouve existe deja." << endl;
		}
	} while (existe == true);

	cout << "Veuillez choisir une position pour le nouveau joueur :  1 pour GARDIEN, 2 pour ATTAQUANT , 3 pour DEFENSEUR,4 pour MILLIEU DE TERRAIN  " << endl;
	int position;
	position = validerEntierEntreIntervalle(Position::GARDIEN_DE_BUT, Position::MILIEU_DE_TERRAIN);
	j.position = (Position)(position);
	return j;

}

/*
	Tâche : fonction qui demande la saisie d'un numéro de joueur et
			cherche dans la liste des joueurs de l'équipe dans le
			but de retrouver ce joueur. Si le numéro du joueur saisi
			correspond au numéro d'un des joueurs de l'équipe, la
			fonction retourne l'indice ou se trouve le joueur dans
			le tableau, sinon la fonction affiche le message
			"Ce joueur n'existe pas" et retourne la valeur -1.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
*/
int rechercherJoueur(joueur joueurs[], const int TAILLE, unsigned short nbJoueurs) {
	//À compléter
	unsigned short numero;
	cout << "                                  Recherche d'un  joueur" << endl;

	cout << "Saisir le numero de joueur recherche " << endl;
	numero = validerNumerique();
	int indiceTrouve = rechercheLineaire(joueurs, TAILLE, numero);
	if (indiceTrouve != -1) {
		cout << "L'indice ou se trouve la valeur recherche " << numero << " est " << indiceTrouve << endl;
		//cout << "Le nom du joueur a lindice " << indiceTrouve << " est " << joueurs[indiceTrouve].nom << endl;
		//cout << "Le prenom du joueur a lindice " << indiceTrouve << " est " << joueurs[indiceTrouve].prenom << endl;

	}
	else {
		cout << "La valeur recherche " << numero << " ne se trouve pas dans l'ensemble." << endl;
	}
	//cout << "indice trouve " << indiceTrouve << endl ;

	return indiceTrouve; // À remplacer car c'est seulement là pour que le code compile 
}
int rechercheLineaire(joueur joueurs[], const int TAILLE, int valeurRecherchee) {
	int indiceTrouve = -1;
	int indiceCourrant = 0;
	while (indiceCourrant < TAILLE && indiceTrouve == -1) {

		if (joueurs[indiceCourrant].noDeJoueur == valeurRecherchee) {//fallait que je rajoute .numero de joueur
			indiceTrouve = indiceCourrant;
		}
		indiceCourrant++;
	}
	return indiceTrouve;

}


/*
	Tâche : fonction qui permet de modifier les informations D'UN SEUL joueur
		 passé en paramètre. Les seules informations que vous pouvez modifier
		 pour un joueur sont le numéro du joueur, le nom, le prénom et la
		 position. Vous ne devez pas permettre de modifier le nombre de buts.
	Paramètre : une référence d'un joueur.
	//, je modifie l'énoncé. Vous ne devez pas modifier le numéro de joueur car la structure actuelle de la fonction ne le permet pas.
	//Modifier seulement le nom, prénom et position
*/
void modifierJoueur(joueur joueurs[], const int TAILLE, joueur& joueur) {
	//À compléter
	unsigned short numero;
	int position;
	char nom[31];
	bool existe = false;
	cout << "                                  Modification d'un  joueur" << endl;

	//do {
		cout << "entrer le numero du joueur a modifier " << endl;
		numero = validerNumerique();
		int indiceTrouve = rechercheLineaire(joueurs, TAILLE, numero);
		if (indiceTrouve != -1) {
			existe = true;
			//cout << "L'indice ou se trouve la valeur recherche " << numero << " est " << indiceTrouve << endl;
			cout << "Saisir un nouveau nom pour le joueur " << endl;
			validerChaine(joueurs[indiceTrouve].nom, TAILLE);
			system("pause"); /******** pourquoi le programme continu? */
			cout << "Saisir un nouveau prenom pour le joueur " << endl;
			validerChaine(joueurs[indiceTrouve].prenom, TAILLE);
			cout << "Entrer choisir une nouvelle position pour joueur :  1 pour GARDIEN, 2 pour ATTAQUANT , 3 pour DEFENSEUR,4 pour MILLIEU DE TERRAIN  " << endl;
			position = validerEntierEntreIntervalle(Position::GARDIEN_DE_BUT, Position::MILIEU_DE_TERRAIN);
			joueurs[indiceTrouve].position = (Position)(position);
			//cout << "Le nom du joueur a lindice " << indiceTrouve << " est " << joueurs[indiceTrouve].nom << endl;
			cout << "le joueur a ete modifie" << endl;

		}
		else {
			existe = false;
			cout << "le numero saisi ne se trouve pas dans l'ensemble." << endl;
		}
	//} while (existe == false || numero>-1);
}


/*
	Tâche : fonction qui retire un joueur du tableau en fonction
			de l'indice où se trouve le joueur dans le tableau.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
				l'indice où se trouve joueur dans le tableau
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void retirerJoueur(joueur joueurs[], const int TAILLE, unsigned short& nbJoueurs) {
	//À compléter

	unsigned short numero;
	int position;
	bool existe = false;
	cout << "                                  Retrait d'un  joueur" << endl;

	/*cout << "entrer le numero du joueur a retirer " << endl;
	numero = validerNumerique();
	if (numero >= nbJoueurs + 1)
		cout << "Le numero recherche " << numero << " ne se trouve pas dans l'ensemble." << endl;
	else
	{
		for (int i = numero - 1; i < nbJoueurs - 1; i++)
			joueurs[i] = joueurs[i + 1];
	}*/

	do {
		cout << "entrer le numero du joueur a retirer " << endl;
		numero = validerNumerique();
		int indiceTrouve = rechercheLineaire(joueurs, TAILLE, numero);
		if (indiceTrouve != -1) {
			existe = true;
			//cout << "L'indice ou se trouve la valeur recherche " << numero << " est " << indiceTrouve << endl;
			for (int i = indiceTrouve - 1; i < nbJoueurs - 1; i++) {
				//joueurs[indiceTrouve] = joueurs[indiceTrouve + 1];

				joueurs[i] = joueurs[i + 1];
				joueurs[i + 1] = {};
				//nbJoueurs--;
				cout << "le joueur a ete retire" << endl;

			}

			//
		}
		else {
			existe = false;
			cout << "La valeur recherche " << numero << " ne se trouve pas dans l'ensemble." << endl;
		}
	} while (existe == false);

}


/*
	Tâche : fonction qui affiche les informations D'UN SEUL joueur
			passé en paramètre.
	Paramètre : une référence constante d'un joueur pour éviter tout
				risque de modification du joueur dans la fonction.
	Retour : aucun (affichage seulement)
*/
void afficherInfoJoueur(const joueur& JOUEUR, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs) {
	//À compléter
	int indice;
	//joueur j = JOUEUR;
	indice = rechercherJoueur(joueurs, TAILLE, nbJoueurs);
	//	joueurs[indice] = JOUEUR;
		//cout << "le nom du joueur est " << indice << endl;

	cout << "le nom du joueur est " << joueurs[indice].nom << endl;
	cout << "le prenom du joueur est " << joueurs[indice].prenom << endl;
	cout << "la position du joueur est " << joueurs[indice].position << endl;
	cout << "le nombre de but du joueur est " << joueurs[indice].nbButs << endl;

}

/*
	Tâche : fonction qui ajoute un but à un joueur passé par référence
			en paramètre.
	Paramètre : une référence d'un joueur
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void ajouterButJoueur(joueur& leJoueur, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs) {
	//À compléter
	int indice;
	int nbButAajouter;
	cout << "                                    Ajout de but a un joueur " << endl;

	cout << "Ajout de but a un joueur " << endl;
	indice = rechercherJoueur(joueurs, TAILLE, nbJoueurs);
	//cout << "entrer le nombre de but a ajouter au joueur " << endl;
	//nbButAajouter = validerNumerique();

	joueurs[indice].nbButs = joueurs[indice].nbButs++;
	cout << "le but a ete ajoute au joueur" << endl;


}

/*
	Tâche : fonction qui retire un but à un joueur passé par référence
			en paramètre. La fonction doit prévoir que le nombre de but
			ne pourra pas jamais être inférieur à 0.
	Paramètre : une référence d'un joueur
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void retirerButJoueur(joueur& leJoueur, joueur joueurs[], const int TAILLE, unsigned short nbJoueurs) {
	//À compléter
	cout << "                                  Retrait de but a un joueur" << endl;

	int indice;
	indice = rechercherJoueur(joueurs, TAILLE, nbJoueurs);
	if (joueurs[indice].nbButs > 0) {
		joueurs[indice].nbButs = joueurs[indice].nbButs--;
		cout << "le but a ete retire " << endl;

	}
	else {
		cout << "le joueur n'a pas de but ; Impossible de lui retirer un but " << endl;

	}
}


/*
	Tâche : fonction qui affiche les joueurs de l'équipe après avoir
			demandé la saisie de la position à afficher. Aussi, ajouter
			une option permettant d'afficher tous les joueurs.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (affichage seulement)
*/
void afficherJoueursParPosition(joueur joueurs[], const int TAILLE, unsigned short nbJoueurs) {
	//À compléter
	int choix1, choix2;
	cout << "  Selectionner un critere d'affichage " << endl;
	cout << "Veuillez selectionner un critere  d'affichage " << endl;
	cout << "1- Afficher tous les Joueurs" << endl;
	cout << "2- Afficher les joueurs par position" << endl;
	choix1 = validerNumerique();
	switch (choix1) {
	case (ChoixAffichage::AFFICHER_TOUS): cout << "Afficher tous les joueurs" << endl;
		afficherTousLesJoueurs(joueurs, nbJoueurs);
		break;       // and exits the switch
	case(ChoixAffichage::AFFICHER_PAR_POSITION): cout << "Afficher  les joueurs  par positions" << endl;
		cout << "Veuillez selectionner une option d'affichage " << endl;
		cout << "1- Gardiens de buts" << endl;
		cout << "2- Attaquants" << endl;
		cout << "3- Defenseurs" << endl;
		cout << "4- Joueurs milieu de terrain" << endl;
		choix2 = validerEntierEntreIntervalle(Position::GARDIEN_DE_BUT, Position::MILIEU_DE_TERRAIN);
		switch (choix2) {
		case(Position::GARDIEN_DE_BUT): cout << "Liste des joueurs Gardiens de buts" << endl;
			for (int i = 0; i < nbJoueurs; i++) {
				if (joueurs[i].position == Position::GARDIEN_DE_BUT) {
					cout << joueurs[i].nom << "  " << joueurs[i].prenom << " Numero:  " << joueurs[i].noDeJoueur << "Position   " << joueurs[i].position << endl;
				}
			}
			break;       // and exits the switch
		case(Position::ATTAQUANT): cout << "Liste des joueurs Attaquants" << endl;
			for (int i = 0; i < nbJoueurs; i++) {
				if (joueurs[i].position == Position::ATTAQUANT) {
					cout << joueurs[i].nom << "  " << joueurs[i].prenom << " Numero: " << joueurs[i].noDeJoueur << " position :  " << joueurs[i].position << endl;
				}
			}
			break;
		case(Position::DEFENSEUR): cout << "Liste des joueurs Defenseurs" << endl;
			for (int i = 0; i < nbJoueurs; i++) {
				if (joueurs[i].position == Position::DEFENSEUR) {
					cout << joueurs[i].nom << "  " << joueurs[i].prenom << "  Numero:  " << joueurs[i].noDeJoueur << " Position:   " << joueurs[i].position << endl;
				}
			}
			break;
		case(Position::MILIEU_DE_TERRAIN): cout << "Liste des joueurs du Millieu de terrain" << endl;
			for (int i = 0; i < nbJoueurs; i++) {
				if (joueurs[i].position == Position::MILIEU_DE_TERRAIN) {
					cout << joueurs[i].nom << "  " << joueurs[i].prenom << "  Numero:  " << joueurs[i].noDeJoueur << " Position:   " << joueurs[i].position << endl;
				}
			}
			break;
		}
		break;
	}

}

/*
	Tâche : fonction qui calcule et affiche le nombre total de but(s)
			marqué(s) pour toutes l'équipes.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (affichage seulement)
*/
void afficherTotalDeButDeLEquipe(joueur joueurs[], unsigned short& nbJoueurs) {
	//À compléter
	int total = 0;
	for (int i = 0; i < nbJoueurs; i++) {
		//cout << joueurs[i].prenom << endl;
		total = total + joueurs[i].nbButs;

	}
	cout << "  le nombre de but total de l'equipe est " << total << endl;

}
int validerNumerique() {
	unsigned int valeur;
	cout << "  veuillez saisir une valeur numerique " << endl;
	cin >> valeur;
	while (cin.fail() == true || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Saisir  une valeur numerique seulement" << endl;
		cin >> valeur;
	}
	cin.ignore(512, '\n');
	return valeur;

}
void validerChaine(char chaine[], const int TAILLE) {
	cin.getline(chaine, TAILLE);
	while (cin.fail()) {
		cin.clear();
		cin.ignore(512, '\n');
		cout << "la longueur maximal de la chaine est 31 " << endl;
		cin.getline(chaine, TAILLE);
	}
}

void afficherTousLesJoueurs(joueur joueurs[], unsigned short& nbJoueurs) {
	cout << "la liste de tous les joueurs est " << endl;

	for (int i = 0; i < nbJoueurs; i++) {
		if (joueurs[i].position != 0)
			cout << joueurs[i].nom << "   " << joueurs[i].prenom << "  Numero:  " << joueurs[i].noDeJoueur << "  Position:  " << joueurs[i].position << endl;
	}

}

unsigned short validerEntierEntreIntervalle(const int NUM_MIN, int const NUM_MAX) {

	unsigned short valeur;
	valeur = validerNumerique();
	while (valeur<NUM_MIN || valeur>NUM_MAX) {

		cout << " saisie invalide veuillez ressayer avec une valeur entre les bornes " << endl;
		valeur = validerNumerique();
	}
	return valeur;
}