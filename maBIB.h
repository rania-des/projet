#include<stdio.h>
#include<stdlib.h>
struct date {
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct client {
    int CIN;
    char nom[50];
    char prenom[50];
    char adresse[50];
    char email[50];
    int telephone;
};
typedef struct client CLIENT;

struct employe {
    char nom[50];
    char prenom[50];
    char role[50];
    float salaire;
};
typedef struct employe EMPLOYEE;

struct stock {
    int idprod;
    int quantite;
    char fournisseur[50];
};
typedef struct stock STOCK;

struct service {
    int id;
    char type[50];
    float tarif;
    int duree;
    EMPLOYEE employe;
};
typedef struct service SERVICE;

struct animale {
    char nom[50];
    char race[50];
    int age;
    char allergies[100];
};
typedef struct animale ANIMAL;

struct rendezvous {
    int id;
    DATE date;
    char heure[50];
    ANIMAL animale;
    CLIENT client;
};
typedef struct rendezvous RENDEZVOUS;

struct avis {
    int cin;
    int note;
    char *commentaire;
};
typedef struct avis AVIS;

struct resultat {
    int id;
    int nombretraitement;
};
typedef struct resultat RESULTAT;



typedef struct ElementPile ElementPile;
struct ElementPile {
    RESULTAT data;
    ElementPile* suivant;
}

typedef struct {
    ElementPile* sommet;
} Pile;

int menu_principal ();
int menu_rendezvous();
int menu_stock();
int menu_services();
int menu_avis();
int menu_RES();
int menu_clients();

//Fonctions pour le remplissage et affichage des structures :

void remplirDate(DATE*);
void afficherDate(DATE*);
void remplirClient(CLIENT*);
void afficherClient(CLIENT*);
void remplirEmployee(EMPLOYEE*);
void afficherEmployee(EMPLOYEE*);
void remplirStock(STOCK*);
void afficherStock(STOCK*);
void remplirService(SERVICE*);
void afficherService(SERVICE*);
void remplirAnimal(ANIMAL*);
void afficherAnimal(ANIMAL*);
void remplirRendezVous(RENDEZVOUS*);
void afficherRendezVous(RENDEZVOUS*);
void remplirAvis(AVIS *, FILE *);
void afficherAvis( AVIS *);

void creerFichierDeRendezvous(FILE**);
void remplirFichierRendezvous(FILE*, int );
RENDEZVOUS lireUnRendezvousDuFichier(FILE*);
void afficherFichierRendezvous(FILE*);
void modifierRendezVous(FILE *, int);
void rechercherRendezVous(FILE *, int );
void supprimerRendezVous(FILE* , int );
int calculerNombreDeTraitements(FILE *, int );
void afficherNombreDeTraitements(FILE *);

void creerFichierDeService(FILE**);
void remplirFichierService(FILE*, int );
SERVICE lireUnServiceDuFichier(FILE*);
void afficherFichierService(FILE*);
void allouerEmploye(EMPLOYEE** );
float calculerSalaireTotal(FILE* );
void modifierService(FILE* , int );
void supprimerService(FILE* , int );
void rechercherService(FILE* , int );
void rechercherServiceLePlusCher(FILE* );

void creerFichierDeStock(FILE**);
void remplirFichierStock(FILE*, int );
STOCK lireUnStockDuFichier(FILE*);
void afficherFichierStock(FILE*);
void chercherProduitsEpuise(FILE*);
void chercherProduitParID(FILE*,  int);
void supprimerProduit(FILE* , int );
void modifierProduit(FILE* , int );

int verifierCINDansRendezvous(FILE *, int );
char* allouerMemoireCommentaire(int );
void remplirFichierAvis(FILE*,FILE*, int );
void afficherFichierAvis(FILE*);
void ecrireAvis(FILE *,  AVIS *);
int lireAvis(FILE *, AVIS *);
void creerFichierAvis(FILE **);
float calculerPourcentageNotes(FILE *);
void chercherAvisParCIN(FILE *, int );


bool estDansAnnee(RENDEZVOUS , int );
void initPile(Pile*);
void push(Pile*,RESULTAT);
RESULTAT pop(Pile*);
RESULTAT peek(Pile*);
int estVide(Pile*);
Pile* trouverTop3ClientsParAnnee(FILE *, int );
Pile* creerTableauTop3ParAnnee(FILE *, int , int );
void afficherTableauTop3ParAnnee(Pile* , int , int );
void libererTableauTop3ParAnnee(Pile* , int , int );


void afficherAnimauxClient(FILE*, int );
