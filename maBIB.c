#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "maBIB.h"
void remplirDate(DATE *date) {
    printf("Entrer le jour : ");
    scanf("%d", &date->jour);
    printf("Entrer le mois : ");
    scanf("%d", &date->mois);
    printf("Entrer l'annee : ");
    scanf("%d", &date->annee);
}
void afficherDate(DATE *date) {
    printf("%02d/%02d/%d\n", date->jour, date->mois, date->annee);
}
void remplirClient(CLIENT *client) {
    printf("Entrer le CIN du client : ");
    scanf("%d", &client->CIN);
    printf("Entrer le nom : ");
    scanf("%49s", client->nom);
    printf("Entrer le prenom : ");
    scanf("%49s", client->prenom);
    printf("Entrer l'adresse : ");
    scanf("%49s", client->adresse);
    printf("Entrer l'email : ");
    scanf("%49s", client->email);
    printf("Entrer le telephone : ");
    scanf("%d", &client->telephone);
}
void afficherClient(CLIENT *client) {
    printf("CIN : %d\nNom : %s\nPrenom : %s",
            client->CIN, client->nom, client->prenom);
    printf("\nAdresse : %s\nEmail : %s\nTelephone : %d\n",
            client->adresse, client->email, client->telephone);
}
void remplirEmployee(EMPLOYEE *employe) {
    printf("Entrer le nom : ");
    scanf("%49s", employe->nom);
    printf("Entrer le prenom : ");
    scanf("%49s", employe->prenom);
    printf("Entrer le role : ");
    scanf("%49s", employe->role);
    printf("Entrer le salaire : ");
    scanf("%f", &employe->salaire);
}
void afficherEmployee(EMPLOYEE *employe) {
    printf("\nNom : %s\nPrenom : %s", employe->nom, employe->prenom );
    printf("\nRole : %s\nSalaire : %.2f",employe->role, employe->salaire);
    printf("\n-----------------------------------\n");
}
void remplirStock(STOCK *stock) {
    printf("Entrer l'ID du produit : ");
    scanf("%d", &stock->idprod);
    printf("Entrer la quantite : ");
    scanf("%d", &stock->quantite);
    printf("Entrer le fournisseur : ");
    scanf("%49s", stock->fournisseur);
}
void afficherStock(STOCK *stock) {
    printf("\n-----------------------------------\n");
    printf("ID produit : %d\nQuantite : %d", stock->idprod, stock->quantite);
    printf("\nFournisseur : %s", stock->fournisseur);
    printf("\n-----------------------------------\n");
}
void remplirService(SERVICE *service) {
    printf("Entrer l'ID du service : ");
    scanf("%d", &service->id);
    printf("Entrer le type de service : ");
    scanf("%49s", service->type);
    printf("Entrer le tarif : ");
    scanf("%f", &service->tarif);
    printf("Entrer la duree estimee (en minutes) : ");
    scanf("%d", &service->duree);

    printf("\n--- Remplissage de l'employe ---\n");
    remplirEmployee(&service->employe);
}
void afficherService(SERVICE *service) {
    printf("\nID Service : %d\nType : %s", service->id, service->type);
    printf("\nTarif : %.2f\nDuree : %d minutes\n", service->tarif, service->duree);
    printf("\nInformations de l'employe :\n");
    afficherEmployee(&service->employe);
}
void remplirAnimal(ANIMAL *animal) {
    printf("Entrer le nom de l'animal : ");
    scanf("%49s", animal->nom);
    printf("Entrer la race : ");
    scanf("%49s", animal->race);
    printf("Entrer l'age : ");
    scanf("%d", &animal->age);
    printf("Entrer les allergies (un mot sans espace) : ");
    scanf("%99s", animal->allergies);
}
void afficherAnimal(ANIMAL *animal) {
    printf("Nom : %s\nRace : %s\nAge : %d\nAllergies : %s\n",
        animal->nom, animal->race, animal->age, animal->allergies);
}
void remplirRendezVous(RENDEZVOUS *rv) {
    printf("Entrer l'ID du rendez-vous : ");
    scanf("%d", &rv->id);
    remplirDate(&rv->date);
    printf("Entrer l'heure du rendez-vous : ");
    scanf("%49s", rv->heure);
    printf("\n--- Remplissage de l'animal ---\n");
    remplirAnimal(&rv->animale);
    printf("\n--- Remplissage du client ---\n");
    remplirClient(&rv->client);
}
void afficherRendezVous(RENDEZVOUS *rv)
{
    printf("\n-----------------------------------\n");
    printf("ID Render-vous : %d\nDate : ", rv->id);
    afficherDate(&rv->date);
    printf("Heure : %s\n", rv->heure);
    if (&rv->animale != NULL)
        printf("\n--Informations de l'animal :\n\n");
        afficherAnimal(&rv->animale);
    if (&rv->client != NULL)
        printf("\n--Informations du client :\n\n");
        afficherClient(&rv->client);
    printf("\n-----------------------------------\n");
}
void remplirAvis(AVIS *avis, FILE *fr) {
    printf("Entrer le CIN : ");
    scanf("%d", &avis->cin);
    if (!verifierCINDansRendezvous(fr, avis->cin)) {
        printf("CIN %d introuvable dans le fichier des rendez-vous.\n", avis->cin);
        exit(-1);
    }
    do {
        printf("Entrer une note (entre 1 et 5) : ");
        scanf("%d", &avis->note);
    } while (avis->note < 1 || avis->note > 5);
    printf("Entrer le commentaire (max 255 caractères) : ");
    avis->commentaire = allouerMemoireCommentaire(256);
    scanf(" %[^\n]", avis->commentaire);
}
void afficherAvis( AVIS *avis) {
    printf("\n--- Avis ---\n");
    printf("CIN : %d\n", avis->cin);
    printf("Note : %d\n", avis->note);
    printf("Commentaire : %s\n", avis->commentaire);
}

int menu_principal (){
    int choix;
    printf("\n***********  Menu  ***********\n");
    printf("    1. Gestion de rendez_vous\n");
    printf("    2. Gestion des services\n");
    printf("    3. Gestion de stock\n");
    printf("    4. Gestion des avis\n");
    printf("    5. Gestion des RESULT\n");
    printf("    6. Gestion des clients\n");
    printf("    7. Quitter\n");
    printf("    Choisissez une option : ");
    scanf("%d", &choix);
    printf("********************************\n");
    return choix;
}
int menu_rendezvous(){
    int x;
    printf("\n***********  Gestion des rendez_vous  ***********\n");
    printf("    1. Ajouter un rendez_vous\n");
    printf("    2. Modifier un rendez_vous\n");
    printf("    3. Supprimer un rendez_vous\n");
    printf("    4. Rechercher un rendez_vous\n");
    printf("    5. Afficher tous les rendez_vous\n");
    printf("    6. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("*************************************************\n");
    return x;
}
int menu_stock(){
    int x;
    printf("\n***********  Gestion de stock  ***********\n");
    printf("    1. Ajouter des produits\n");
    printf("    2. afficher les produits\n");
    printf("    3. Modifier un produit\n");
    printf("    4. Rechercher un produit\n");
    printf("    5. Rechercher un produit epuise\n");
    printf("    6. Supprimer un produit \n");
    printf("    7. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("******************************************\n");
    return x;
}
int menu_services(){
    int x;
    printf("\n***********  Gestion des services  ***********\n");
    printf("    1. Ajouter un service\n");
    printf("    2. Modifier un service\n");
    printf("    3. Supprimer un service\n");
    printf("    4. Rechercher un service\n");
    printf("    5. Afficher tous les services\n");
    printf("    6. Calculer les salaires totaux\n");
    printf("    7. Afficher le service le plus cher\n");
    printf("    8. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("**********************************************\n");
    return x;
}
int menu_avis(){
    int x;
    printf("\n***********  Gestion des avis  ***********\n");
    printf("    1. Ajouter un avis\n");
    printf("    2. chercher un avis par cin\n");
    printf("    3. calculer Pourcentage Notes >=3\n");
    printf("    4. Afficher tous les avis\n");
    printf("    5. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("******************************************\n");
    return x;
}
int menu_RES(){
    int x;
    printf("\n***********  Gestion de structure RESULT  ***********\n");
    printf("    1. Trouver et afficher les trois meilleurs clients\n");
    printf("    2. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("*****************************************************\n");
    return x;
}
int menu_clients(){
    int x;
    printf("\n***********  Gestion des clients  ***********\n");
    printf("    1. afficher les animaux du clients par CIN\n");
    printf("    2. afficher le nombre des traitements du client\n");
    printf("    3. Retour\n");
    printf("    Choisissez une option : ");
    scanf("%d", &x);
    printf("******************************************\n");
    return x;
}
void creerFichierDeStock(FILE**fs){
	*fs= fopen("C:\\New folder\\stock.txt","rb+");
	if(!*fs) {
        *fs= fopen("C:\\New folder\\stock.txt","wb+");
        if(!*fs) exit(-1);
    }
}
void remplirFichierStock(FILE*fs, int nbProd){
	STOCK sto;
    printf("donner le nombre des produits a ajouter :");
    scanf("%d",&nbProd);
    for(int i=0;i<nbProd;i++)
    {
        remplirStock(&sto);
        fwrite(&sto ,sizeof(STOCK), 1 , fs);
    }
}
STOCK lireUnStockDuFichier(FILE*fs){
	STOCK sto;
	fread(&sto ,sizeof(STOCK), 1 , fs);
	return sto;
}
void afficherFichierStock(FILE* fs){
    STOCK sto;
    rewind(fs);
    while (fread(&sto, sizeof(STOCK), 1, fs)) {
        afficherStock(&sto);
    }
}

void chercherProduitsEpuise(FILE* fs) {
    STOCK sto;
    int erreur=0;
    rewind(fs);
    while (fread(&sto, sizeof(STOCK), 1, fs)) {
        if (sto.quantite == 0) {
            printf("Produits epuises :\n");
            afficherStock(&sto);
            erreur=1;
        }
    }
    if (erreur==0) printf("il n'y a pas");
}
void chercherProduitParID(FILE* fs, int idCherche) {
    STOCK sto;
    int trouve = 0;
    rewind(fs);
    printf("Entrer l'ID du produit a chercher : ");
    scanf("%d", &idCherche);
    while (fread(&sto, sizeof(STOCK), 1, fs)) {
        if (sto.idprod == idCherche) {
            printf("Produit trouve :\n");
            afficherStock(&sto);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("Produit avec ID %d non trouve.\n", idCherche);
    }
}

void supprimerProduit(FILE* fs, int idprodsupprimer) {
    FILE* tempFile = fopen("C:\\New folder\\temp_stock.txt", "wb+");
    if (tempFile == NULL) {
        printf("Erreur d'ouverture du fichier temporaire.\n");
        exit(-1);
    }
    STOCK sto;
    int found = 0;
    rewind(fs);
    printf("Entrer l'ID du produit a supprimer : ");
    scanf("%d", &idprodsupprimer);
    while (fread(&sto, sizeof(STOCK), 1, fs)) {
        if (sto.idprod != idprodsupprimer) {
            fwrite(&sto, sizeof(STOCK), 1, tempFile);
        } else {
            found = 1;
        }
    }
    if (!found) {
        printf("Produit avec l'ID %d non trouve.\n", idprodsupprimer);
    } else {
        printf("Produit avec l'ID %d supprime avec succes.\n", idprodsupprimer);
    }
    fclose(fs);
    fclose(tempFile);
    remove("C:\\New folder\\stock.txt");
    rename("C:\\New folder\\temp_stock.txt", "C:\\New folder\\stock.txt");
    fs = fopen("C:\\New folder\\stock.txt", "rb+");
    if (fs == NULL) {
        printf("Erreur lors de la reouverture du fichier apres la suppression.\n");
        exit(-1);
    }
}
void modifierProduit(FILE* fs, int idprod) {
    fseek(fs, 0, SEEK_SET);
    STOCK sto;
    int found = 0;
    printf("Entrer l'ID du produit a modifier : ");
    scanf("%d", &idprod);
    while (fread(&sto, sizeof(STOCK), 1, fs)) {
        if (sto.idprod == idprod) {
            printf("Produit trouve : ID = %d\n", sto.idprod);
            printf("Modifier les informations du produit\n");
            printf("Entrer la nouvelle quantite : ");
            scanf("%d", &sto.quantite);
            printf("Entrer le nouveau fournisseur : ");
            scanf("%49s", sto.fournisseur);
            fseek(fs, -sizeof(STOCK), SEEK_CUR);
            fwrite(&sto, sizeof(STOCK), 1, fs);
            found = 1;
            printf("Produit modifie avec succes.\n");
            break;
        }
    }
    if (!found) {
        printf("Produit avec l'ID %d non trouve.\n", idprod);
    }
    fseek(fs, 0, SEEK_END);
}





void creerFichierDeService(FILE**fss){
	*fss= fopen("C:\\New folder\\service.txt","rb+");
	if(!*fss) {
        *fss= fopen("C:\\New folder\\service.txt","wb+");
        if(!*fss) exit(-1);
    }
}
void remplirFichierService(FILE*fss, int nbService){
	SERVICE ser;
    printf("Donner le nombre des services a ajouter: ");
    scanf("%d", &nbService);
    for(int i=0;i<nbService;i++)
    {
        printf("\n--- Service %d ---\n", i + 1);
        remplirService(&ser);
        fwrite(&ser ,sizeof(SERVICE), 1 , fss);
    }
}
SERVICE lireUnServiceDuFichier(FILE*fss){
	SERVICE ser;
	fread(&ser ,sizeof(SERVICE), 1 , fss);
	return ser;
}

void afficherFichierService(FILE*fss){
	SERVICE ser;
	rewind(fss);
	while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        afficherService(&ser);
    }
}
void allouerEmploye(EMPLOYEE** employe) {
    *employe = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));
    if (*employe == NULL) {
        printf("Erreur d'allocation mémoire pour l'employé.\n");
        exit(-1);
    }
}

float calculerSalaireTotal(FILE* fss) {
    SERVICE ser;
    float salaireTotal = 0.0;

    rewind(fss);
    while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        salaireTotal += ser.employe.salaire;
    }

    return salaireTotal;
}

void modifierService(FILE* fss, int idService) {
    SERVICE ser;
    rewind(fss);
    printf("Donner le ID de service a modifier: ");
    scanf("%d", &idService);
    while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        if (ser.id == idService) {
            printf("\nService trouve. Entrez les nouvelles informations du service :\n");
            printf("Entrer le tarif : ");
            scanf("%f", &ser.tarif);
             printf("Entrer la duree estimee (en minutes) : ");
            scanf("%d", &ser.duree);
            printf("\n Entrez les nouvelles informations de l'employe :\n");
            remplirEmployee(&ser.employe);
            fseek(fss, -sizeof(SERVICE), SEEK_CUR);
            fwrite(&ser, sizeof(SERVICE), 1, fss);
            printf("\nLe service avec l'ID %d a ete modifie avec succes.\n", idService);
            return;
        }
    }
    printf("\nService avec l'ID %d introuvable.\n", idService);
}
void supprimerService(FILE* fss, int idService) {
    FILE* tempFile = fopen("C:\\New folder\\temp_service.txt", "wb+");
    if (tempFile == NULL) {
        printf("Erreur d'ouverture du fichier temporaire.\n");
        exit(-1);
    }
    SERVICE ser;
    int found = 0;
    printf("Donner le ID de service a supprimer: ");
    scanf("%d", &idService);
    rewind(fss);
    while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        if (ser.id != idService) {
            fwrite(&ser, sizeof(SERVICE), 1, tempFile);
        } else {
            found = 1;
        }
    }
    if (!found) {
        printf("Service avec l'ID %d non trouve.\n", idService);
    } else {
        printf("Service avec l'ID %d supprime avec succee.\n", idService);
    }
    fclose(fss);
    fclose(tempFile);
    remove("C:\\New folder\\service.txt");
    rename("C:\\New folder\\temp_service.txt", "C:\\New folder\\service.txt");
    fss = fopen("C:\\New folder\\service.txt", "rb+");
    if (fss == NULL) {
        printf("Erreur lors de la reouverture du fichier après la suppression.\n");
        exit(-1);
    }
}
void rechercherService(FILE* fss, int idService) {
    SERVICE ser;
    int found = 0;
    printf("Donner le ID de service a chercher: ");
    scanf("%d", &idService);
    rewind(fss);
    while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        if (ser.id == idService) {
            printf("Service trouve :\n");
            afficherService(&ser);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Service avec l'ID %d non trouve.\n", idService);
    }
}
void rechercherServiceLePlusCher(FILE* fss) {
    SERVICE ser;
    float tarifMax = 0.0;
    SERVICE serviceMax;
    int found = 0;
    rewind(fss);
    while (fread(&ser, sizeof(SERVICE), 1, fss)) {
        if (ser.tarif > tarifMax) {
            tarifMax = ser.tarif;
            serviceMax = ser;
            found = 1;
        }
    }
    if (found) {
        printf("Le service le plus cher est :\n");
        afficherService(&serviceMax);
    } else {
        printf("Aucun service trouve.\n");
    }
}

void creerFichierDeRendezvous(FILE**fr){
	*fr= fopen("C:\\New folder\\rendezvous.txt","rb+");
	if(!*fr) {
        *fr= fopen("C:\\New folder\\rendezvous.txt","wb+");
        if (!*fr) exit(-1);
    }
}
void remplirFichierRendezvous(FILE*fr, int nbRendezvous){
	RENDEZVOUS ren;
	printf("Donner le nombre des rendezvous a ajouter: ");
    scanf("%d", &nbRendezvous);
    for(int i=0;i<nbRendezvous;i++){
        printf("\n--- Rendezvous %d ---\n", i + 1);
        remplirRendezVous(&ren);
        fwrite(&ren ,sizeof(RENDEZVOUS), 1 , fr);
    }
}
RENDEZVOUS lireUnRendezvousDuFichier(FILE*fr){
	RENDEZVOUS ren;
	fread(&ren ,sizeof(RENDEZVOUS), 1 , fr);
	return ren;
}
void afficherFichierRendezvous(FILE*fr){
	RENDEZVOUS ren;
	rewind(fr);
	while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        afficherRendezVous(&ren);
    }
}
void modifierRendezVous(FILE *fr, int id) {
    FILE *tempFile = fopen("temp_rendezvous.txt", "wb");
    if (tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire!\n");
        exit(EXIT_FAILURE);
    }
    RENDEZVOUS ren;
    rewind(fr);
    printf("Donner le ID de rendezvous a modifier: ");
    scanf("%d", &id);
    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (ren.id == id) {
            printf("Modifier les informations du rendez-vous :\n");
            remplirRendezVous(&ren);
        }
        fwrite(&ren, sizeof(RENDEZVOUS), 1, tempFile);
    }
    fclose(fr);
    fclose(tempFile);
    remove("C:\\New folder\\rendezvous.txt");
    rename("temp_rendezvous.txt", "C:\\New folder\\rendezvous.txt");
    fr = fopen("C:\\New folder\\rendezvous.txt", "rb+");
    if (fr == NULL) {
        printf("Erreur lors de la reouverture du fichier apres la modification.\n");
        exit(-1);
    }
}

void rechercherRendezVous(FILE *fr, int id) {
    RENDEZVOUS ren;
    rewind(fr);
    int found = 0;
    printf("Donner le ID de rendezvous a chercher: ");
    scanf("%d", &id);
    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (ren.id == id) {
            afficherRendezVous(&ren);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Rendez-vous avec l'ID %d non trouve.\n", id);
    }
}

void supprimerRendezVous(FILE* fr, int idRendezVous) {
    FILE* tempFile = fopen("C:\\New folder\\temp_rendezvous.txt", "wb+");
    if (tempFile == NULL) {
        printf("Erreur d'ouverture du fichier temporaire.\n");
        exit(-1);
    }
    RENDEZVOUS rv;
    int found = 0;
    printf("Donner le ID de rendezvous a supprimer: ");
    scanf("%d", &idRendezVous);
    rewind(fr);
    while (fread(&rv, sizeof(RENDEZVOUS), 1, fr)) {
        if (rv.id != idRendezVous) {
            fwrite(&rv, sizeof(RENDEZVOUS), 1, tempFile);
        } else {
            found = 1;
        }
    }
    if (!found) {
        printf("Rendez-vous avec l'ID %d non trouve.\n", idRendezVous);
    } else {
        printf("Rendez-vous avec l'ID %d supprime avec succes.\n", idRendezVous);
    }
    fclose(fr);
    fclose(tempFile);
    remove("C:\\New folder\\rendezvous.txt");
    rename("C:\\New folder\\temp_rendezvous.txt", "C:\\New folder\\rendezvous.txt");
    fr = fopen("C:\\New folder\\rendezvous.txt", "rb+");
    if (fr == NULL) {
        printf("Erreur lors de la reouverture du fichier apres la suppression.\n");
        exit(-1);
    }
}
int calculerNombreDeTraitements(FILE *fr, int CIN) {
    RENDEZVOUS ren;
    int compteur = 0;
    rewind(fr);
    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (ren.client.CIN == CIN) {
            compteur++;
        }
    }
    return compteur;
}
void afficherNombreDeTraitements(FILE *fr) {
    int CIN;
    printf("Entrer le CIN du client : ");
    scanf("%d", &CIN);

    int nbTraitements = calculerNombreDeTraitements(fr, CIN);
    printf("Le client avec le CIN %d a %d traitements.\n", CIN, nbTraitements);
}

bool estDansAnnee(RENDEZVOUS ren, int annee) {
    return ren.date.annee == annee;
}

void initPile(Pile* pile) {
    pile->sommet = NULL;
}

void push(Pile* pile, RESULTAT data) {
    ElementPile* nouvelElement = malloc(sizeof(ElementPile));
    nouvelElement->data = data;
    nouvelElement->suivant = pile->sommet;
    pile->sommet = nouvelElement;
}

RESULTAT pop(Pile* pile) {
    if (pile->sommet == NULL) {
        fprintf(stderr, "Erreur : pile vide\n");
        exit(EXIT_FAILURE);
    }
    ElementPile* temp = pile->sommet;
    RESULTAT data = temp->data;
    pile->sommet = temp->suivant;
    free(temp);
    return data;
}


RESULTAT peek(Pile* pile) {
    if (pile->sommet == NULL) {
        fprintf(stderr, "Erreur : pile vide\n");
        exit(EXIT_FAILURE);
    }
    return pile->sommet->data;
}

int estVide(Pile* pile) {
    return pile->sommet == NULL;
}


Pile trouverTop3ClientsParAnnee(FILE* fr, int annee) {
    rewind(fr);
    RESULTAT* clients = NULL;
    int taille = 0;
    RENDEZVOUS ren;

    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (!estDansAnnee(ren, annee)) {
            continue;
        }
        int trouve = 0;
        for (int i = 0; i < taille; i++) {
            if (clients[i].id == ren.client.CIN) {
                clients[i].nombretraitement++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            taille++;
            clients = realloc(clients, taille * sizeof(RESULTAT));
            clients[taille - 1].id = ren.client.CIN;
            clients[taille - 1].nombretraitement = 1;
        }
    }

    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (clients[i].nombretraitement < clients[j].nombretraitement) {
                RESULTAT temp = clients[i];
                clients[i] = clients[j];
                clients[j] = temp;
            }
        }
    }

    Pile pileTop3;
    initPile(&pileTop3);
    for (int i = 0; i < 3 && i < taille; i++) {
        push(&pileTop3, clients[i]);
    }

    free(clients);
    return pileTop3;
}

Pile* creerTableauTop3ParAnnee(FILE* fr, int annee_min, int annee_max) {
    int nombre_annee = annee_max - annee_min + 1;
    Pile* tableau = malloc(nombre_annee * sizeof(Pile));

    for (int i = 0; i < nombre_annee; i++) {
        int annee_actuel = annee_min + i;
        tableau[i] = trouverTop3ClientsParAnnee(fr, annee_actuel);
    }
    return tableau;
}

void afficherTableauTop3ParAnnee(Pile* tableau, int annee_min, int annee_max) {
    int nombre_annee = annee_max - annee_min + 1;

    for (int i = 0; i < nombre_annee; i++) {
        printf("Année %d :\n", annee_min + i);
        Pile pileTop3 = tableau[i];
        while (!estVide(&pileTop3)) {
            RESULTAT client = pop(&pileTop3);
            printf("  Client ID : %d, Nombre de traitements : %d\n",
                   client.id, client.nombretraitement);
        }
        printf("\n");
    }
}

void libererTableauTop3ParAnnee(Pile* tableau, int annee_min, int annee_max) {
    int nombre_annee = annee_max - annee_min + 1;

    for (int i = 0; i < nombre_annee; i++) {
        Pile* pile = &tableau[i];
        while (!estVide(pile)) {
            pop(pile);
        }
    }
    free(tableau);
}


void creerFichierAvis(FILE **fa) {
    *fa = fopen("C:\\New folder\\avis.txt", "rb+");
    if (!*fa) {
        *fa = fopen("C:\\New folder\\avis.txt", "wb+");
        if (!*fa) exit(-1);
    }
}
int verifierCINDansRendezvous(FILE *fr, int cin) {
    RENDEZVOUS ren;
    rewind(fr);
    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (ren.client.CIN == cin) {
            return 1;
        }
    }
    return 0;
}
char* allouerMemoireCommentaire(int taille) {
    char *commentaire = (char *)malloc(taille * sizeof(char));
    if (commentaire == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    return commentaire;
}
void remplirFichierAvis(FILE*fa,FILE*fr, int nbAvis){
	AVIS avi;
    printf("Donner le nombre des avis a ajouter: ");
    scanf("%d", &nbAvis);
    for(int i=0;i<nbAvis;i++)
    {
        printf("\n--- Avis %d ---\n", i + 1);
        remplirAvis(&avi,fr);
        ecrireAvis(fa,&avi);
    }
}
void afficherFichierAvis(FILE*fa){
	AVIS avi;
	rewind(fa);
	while (lireAvis(fa,&avi)) {
        afficherAvis(&avi);
        free(avi.commentaire);
    }
}
void ecrireAvis(FILE *fw,  AVIS *avis) {
    int taille = strlen(avis->commentaire) + 1;
    fwrite(&avis->cin, sizeof(int), 1, fw);
    fwrite(&avis->note, sizeof(int), 1, fw);
    fwrite(&taille, sizeof(int), 1, fw);
    fwrite(avis->commentaire, sizeof(char), taille, fw);
}
int lireAvis(FILE *fa, AVIS *avis) {
    if (fread(&avis->cin, sizeof(int), 1, fa) != 1) return 0;
    if (fread(&avis->note, sizeof(int), 1, fa) != 1) return 0;

    int taille;
    if (fread(&taille, sizeof(int), 1, fa) != 1) return 0;
    if (taille <= 0 || taille > 1000) {
        printf("Erreur : Taille de commentaire invalide (%d).\n", taille);
        return 0;
    }
    avis->commentaire = allouerMemoireCommentaire(taille);
    if (fread(avis->commentaire, sizeof(char), taille, fa) != (size_t)taille) {
        free(avis->commentaire);
        return 0;
    }
    return 1;
}
float calculerPourcentageNotes(FILE *fa) {
    int totalNotes = 0;
    int notesSuperieuresOuEgalesA3 = 0;
    AVIS avis;
    rewind(fa);
    while (lireAvis(fa, &avis)) {
        totalNotes++;
        if (avis.note >= 3) {
            notesSuperieuresOuEgalesA3++;
        }
        free(avis.commentaire);
    }
    if (totalNotes == 0) {
        return 0;
    }
    return ((float)notesSuperieuresOuEgalesA3 / totalNotes) * 100;
}

void chercherAvisParCIN(FILE *fa, int cinRecherche) {
    AVIS avis;
    rewind(fa);
    printf("Entrer le CIN a rechercher : ");
    scanf("%d", &cinRecherche);
    while (lireAvis(fa, &avis)) {
        if (avis.cin == cinRecherche) {
            printf("\n--- Avis Trouve ---\n");
            printf("CIN : %d\n", avis.cin);
            printf("Note : %d\n", avis.note);
            printf("Commentaire : %s\n", avis.commentaire);
            free(avis.commentaire);
            return;
        }
        free(avis.commentaire);
    }
    printf("Aucun avis trouve pour le CIN %d.\n", cinRecherche);
}

void afficherAnimauxClient(FILE *fr, int CIN_client) {
    RENDEZVOUS ren;
    int found = 0;
    rewind(fr);
    printf("Entrer le CIN du client pour afficher ses animaux : ");
    scanf("%d", &CIN_client);
    while (fread(&ren, sizeof(RENDEZVOUS), 1, fr)) {
        if (ren.client.CIN == CIN_client) {
            printf("\n--- Animal du client %d ---\n", CIN_client);
            afficherAnimal(&ren.animale);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun animal trouve pour le client avec le CIN %d.\n", CIN_client);
    }
}
