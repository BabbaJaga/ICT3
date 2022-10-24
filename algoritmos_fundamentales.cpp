//Sergio Gutierrez Gonzalez A01769367
//Halim Abraham Hamanoiel Galindo A01769137

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>


using namespace std;

struct ProdStructure{
    int id;
    char name[21];
    char type[21];
    char measureUnit[21];
    int price;
    int initialExistence;
    int currentExistence;
    int minStock;
    int maxStock;
    ProdStructure *next,*prev;
};
ProdStructure *h,*t,*n;

struct ActStructure{
    int id;
    char date[11];
    int amount;
    char transactionType;
    char subTransactionType;
    ActStructure *next,*prev;
};
ActStructure *h0,*t0,*n0;

class Product{
    private:
        int counter=0;
    public:
        void menu(){
            system("CLS");
            char option;
            while(option!='x'){
                printf("**************************************\n");
                printf("*********MENU NUEVOS PRODUCTOS********\n");
                printf("**************************************\n");
                printf("a)Alta nuevos productos\n");
                printf("b)Baja productos obsoletos \n");
                printf("c)Consulta productos por clave\n");
                printf("d)Consulta productos por familia\n");
                printf("x)Menu principal\n");
                printf("Indica la opcion deseada: ");
                cin>>option;
                switch(option){
                    case 'a':
                        system("CLS");
                        subscribe();
                        break;
                    case 'b':
                        system("CLS");
                        unsubscribe();
                        break;
                    case 'c':
                        system("CLS");
                        consultKey();
                        break;
                    case 'd':
                        system("CLS");
                        consultFam();
                        break;
                    case 'x':
                        system("CLS");
                        int main();
                        break;
                    default:
                        system("CLS");
                        printf("La opcion ingresada no es valida!\n");
                        break;
                }
            }
        }
        void listCleaner(){
            delete h,t;
            h=NULL;
            t=NULL;
        }
        void fileLoad(){
            listCleaner();
            ProdStructure *k;
            ifstream load;
            load.open("productos.txt",ios::in);
            while(!load.eof()){
                n=new ProdStructure;
                if(h==NULL){
                    //delete printf
                    printf("Node cleared for file loading...!\n");
                    h=n;
                    t=n;
                    h->next=NULL;
                    h->prev=NULL;
                }
                else{
                    k=t;
                    t->next=n;
                    t=n;
                    t->prev=k;
                    t->next=NULL;
                }
                load>>t->id>>t->name>>t->type>>t->measureUnit>>t->price>>t->initialExistence>>t->currentExistence>>t->minStock>>t->maxStock;
            }
            load.close();
        }
        void fileUpdate(){
            ProdStructure *it;
            it=h;
            ofstream update;
            update.open("productos.txt",ios::out);
            while(true){
                if(it->next==NULL){
                    update<<it->id<<' '<<it->name<<' '<<it->type<<' '<<it->measureUnit<<' '<<it->price<<' '<<it->initialExistence<<' '<<it->currentExistence<<' '<<it->minStock<<' '<<it->maxStock;
                    update.close();
                    break;
                }
                else{
                    update<<it->id<<' '<<it->name<<' '<<it->type<<' '<<it->measureUnit<<' '<<it->price<<' '<<it->initialExistence<<' '<<it->currentExistence<<' '<<it->minStock<<' '<<it->maxStock<<endl;
                    it=it->next;
                }
            }
        }
        void listCleanerActivity(){
            delete h0,t0;
            h0=NULL;
            t0=NULL;
        }
        void fileLoadActivity(){
            listCleanerActivity();
            ActStructure *k0;
            string something;
            ifstream load;
            load.open("movimientos.txt",ios::in);
            while(getline(load,something)){
                n0=new ActStructure;
                if(h0==NULL){
                    printf("File Loaded!\n");
                    h0=n0;
                    t0=n0;
                    h0->next=NULL;
                    h0->prev=NULL;
                }
                else{
                    k0=t0;
                    t0->next=n0;
                    t0=n0;
                    t0->prev=k0;
                    t0->next=NULL;
                }
                load>>t0->id>>t0->date>>t0->amount>>t0->transactionType>>t0->subTransactionType;
                cout<<t0->id<<t0->date<<t0->amount<<t0->transactionType<<t0->subTransactionType<<endl;
            }
            load.close();
        }
        void fileUpdateActivity(){
            ActStructure *it0;
            it0=h0;
            ofstream update;
            update.open("movimientos.txt",ios::out);
            while(true){
                if(it0->next==NULL){
                    update<<it0->id<<' '<<it0->date<<' '<<it0->amount<<' '<<it0->transactionType<<' '<<it0->subTransactionType;
                    update.close();
                    break;
                }
                else{
                    update<<it0->id<<' '<<it0->date<<' '<<it0->amount<<' '<<it0->transactionType<<' '<<it0->subTransactionType<<endl;
                    it0=it0->next;
                }
            }
        }
        void idVerification(int matchCheck){
            ProdStructure *it;
            it=h;
            while(true){
                if(it->id==matchCheck && h!=t && it!=t){
                    cout<<"El id "<<matchCheck<<" ya ha sido registrado!\n";
                    printf("Ingrese el id: ");
                    cin>>t->id;
                    objectValidation(t->id);
                    idVerification(t->id);
                }
                else if(it->id==t->id){
                    break;
                }
                it=it->next;
            }
        }
        void objectValidation(int obj){
            if(obj>999999 || obj<1){
                if(counter==0){
                    printf("El valor maximo para la CLAVE es '99,999', ingrese un valor dentro del rango: ");
                    cin>>t->id;
                    objectValidation(t->id);
                }
                else if(counter==1){
                    printf("El precio maximo de un producto es '999,999', ingrese un valor dentro del rango: ");
                    cin>>t->price;
                    objectValidation(t->price);
                }
                else if(counter==2){
                    printf("El valor maximo inicial es '999,999', ingrese un valor dentro del rango:");
                    cin>>t->initialExistence;
                    objectValidation(t->initialExistence);
                }
                else if(counter==3){
                    printf("El valor maximo para el stock minimo es '999,999', ingrese un valor dentro del rango:");
                    cin>>t->minStock;
                    objectValidation(t->minStock);
                }
                else if(counter==4){
                    printf("El valor maximo para el stock maximo es '999,999', ingrese un valor dentro del rango:");
                    cin>>t->maxStock;
                    objectValidation(t->maxStock);
                }
            }
            else{
                if(counter==4){
                    counter=-1;
                }
                counter++;
            }
        }
        void subscribe(){
            fileLoad();
            ProdStructure *k;
            n=new ProdStructure;
            if(h==NULL){
                printf("The file content has not been loaded correctly or was already empty!\n");
                h=n;
                t=n;
                h->prev=NULL;
            }
            else{
                k=t;
                t->next=n;
                t=n;
                t->prev=k;
                t->next=NULL;
            }
            printf("Ingresa la clave: ");
            cin>>t->id; objectValidation(t->id); idVerification(t->id);
            cout<<"La clave "<<t->id<<" esta disponible para ser registrada\n";
            printf("Ingresa el nombre: ");
            cin>>t->name;
            printf("Ingresa la familia del producto: ");
            cin>>t->type;
            printf("Ingresa la unidad de medida: ");
            cin>>t->measureUnit;
            printf("Ingresa el precio unitario: ");
            cin>>t->price; objectValidation(t->price);
            printf("Ingresa la existencia inicial: ");
            cin>>t->initialExistence; objectValidation(t->initialExistence);
            t->currentExistence=t->initialExistence;
            printf("Ingresa el stock minimo: ");
            cin>>t->minStock; objectValidation(t->minStock);
            printf("Ingresa el stock maximo: ");
            cin>>t->maxStock; objectValidation(t->maxStock);
            cout<<"Producto con clave: "<<t->id<<" ha sido registrado!"<<endl;
            fileUpdate();
        }
        void unsubscribeActivity(int deletion){
            fileLoadActivity();
            ActStructure *it0;
            it0=h0;
            if(h0==NULL){
                printf("El archivo no ha sido cargado correctamento o esta vacio.\n");
            }
            else{
                while(true){
                    if(it0->id==deletion){
                        //case first
                        if(it0->prev==NULL && it0->next!=NULL){
                            h0=it0->next;
                            h0->prev=NULL;
                            it0->next=NULL;
                            //printf("The new first Node is: %d\n",h->id);
                            it0=it0->next;
                        }
                        //case middle
                        else if(it0->prev!=NULL && it0->next!=NULL){
                            it0->prev->next=it0->next;
                            it0->next->prev=it0->prev;
                            it0=it0->next;
                        }
                        //case last
                        else if(it0->prev!=NULL && it0->next==NULL){
                            t0=it0->prev;
                            t0->next=NULL;
                            it0->prev=NULL;
                            break;
                        }
                        else{
                            //printf("The unique Node in the list has been deleted!\n");
                            delete[] it0;
                            h0=NULL;
                            t0=NULL;
                            break;
                        }
                    }
                    else{
                        it0=it0->next;
                    }
                }
            }
            fileUpdateActivity();
        }
        void unsubscribe(){
            fileLoad();
            ProdStructure *it;
            int deletion;
            it=h;
            if(h==NULL){
                printf("El archivo no ha sido cargado correctamento o esta vacio.\n");
            }
            else{
                printf("Ingresa la clave de un prducto para removerlo de la base de datos: ");
                cin>>deletion;
                while(true){
                    if(it->id==deletion){
                        //case first
                        if(it->prev==NULL && it->next!=NULL){
                            h=it->next;
                            h->prev=NULL;
                            it->next=NULL;
                            //printf("The new first Node is: %d\n",h->id);
                            break;
                        }
                        //case middle
                        else if(it->prev!=NULL && it->next!=NULL){
                            it->prev->next=it->next;
                            it->next->prev=it->prev;
                            break;
                        }
                        //case last
                        else if(it->prev!=NULL && it->next==NULL){
                            t=it->prev;
                            t->next=NULL;
                            it->prev=NULL;
                            break;
                        }
                        else{
                            //printf("The unique Node in the list has been deleted!\n");
                            delete[] it;
                            h=NULL;
                            t=NULL;
                            break;
                        }
                    }
                    else{
                        it=it->next;
                    }
                }
            }
            fileUpdate();
            unsubscribeActivity(deletion);
        }
        void consultKey(){
            fileLoad();
            ProdStructure *it;
            it=h;
            if(h==NULL){
                printf("The file content has not been loaded correctly or was already empty!\n");
            }
            else{
                printf("Ingresa la clave de un producto para realizar la busqueda: ");
                int matchId;
                cin>>matchId;
                while(true){
                    if(it->id==matchId){
                        cout<<"Clave               : "<<matchId<<endl;
                        cout<<"Nombre              : "<<it->name<<endl;
                        cout<<"Familia             : "<<it->type<<endl;
                        cout<<"Unidad de medida    : "<<it->measureUnit<<endl;
                        cout<<"Precio unitario     : "<<it->price<<endl;
                        cout<<"Existencia inicial  : "<<it->initialExistence<<endl;
                        cout<<"Existencia actual   : "<<it->currentExistence<<endl;
                        cout<<"Stock minimo        : "<<it->minStock<<endl;
                        cout<<"Stock maximo        : "<<it->maxStock<<endl;
                        break;
                    }
                    else{
                        if(it->next==NULL && matchId!=it->id){
                            printf("El producto con la clave ingresada no ha sido encontrado.\n");
                            break;
                        }
                        it=it->next;
                    }
                }
            }
        }
        void consultFam(){
            ProdStructure *it;
            it=h;
            if(h==NULL){
                printf("The file content has not been loaded correctly or was already empty!\n");
            }
            else{
                int matchCount=0;
                char matchFam[21];
                printf("Ingresa la familia del producto para realizar la busqueda: ");
                cin>>matchFam;
                system("CLS");
                cout<<"Familia a consultar: "<<matchFam<<endl;
                while(true){
                    if(strcmp(matchFam,it->type)==0){
                        cout<<"Nombre del producto: "<<it->name<<endl;
                        matchCount++;
                    }
                    else if(it->next==NULL && strcmp(matchFam,it->type)==0 && matchCount==0){
                        cout<<"La categoria " <<matchFam<<" no ha sido encontrada.\n"<<endl;
                        break;
                    }
                    if(it->next==NULL){
                        break;
                    }
                    it=it->next;
                }
            }
        }
};

class Activity{
    public:
        Product prod;
        int acquisition=0;
        int matchId=0;
        char dt[11];
        char transaction, subTransaction;
    public:
        void menu(){
            char option;
            while(option!='x'){
                printf("*****************************\n");
                printf("********Activity menu********\n");
                printf("*****************************\n");
                printf("a)Entradas por compras\n");
                printf("b)Entradas por devolucion a clientes\n");
                printf("c)Salidas por ventas\n");
                printf("d)Salidas por devolucion a proveedores\n");
                printf("e)Salida por mermas\n");
                printf("x)Regresar al menu principal\n");
                printf("Access to: ");
                cin>>option;
                switch(option){
                    case 'a':
                        transaction='E';
                        subTransaction='C';
                        stockManagement();
                        break;
                    case 'b':
                        transaction='E';
                        subTransaction='D';
                        stockManagement();
                        break;
                    case 'c':
                        transaction='S';
                        subTransaction='V';
                        stockManagement();
                        break;
                    case 'd':
                        transaction='S';
                        subTransaction='P';
                        stockManagement();
                        break;
                    case 'e':
                        transaction='S';
                        subTransaction='M';
                        stockManagement();
                        break;
                    case 'x':
                        int main();
                        break;
                    default:
                        system("CLS");
                        printf("La opcion ingresada no es valida!\n");
                        break;
                }
            }
        }
        void dateTime(){
            time_t T=time(0);
            strftime(dt,11,"%m/%d/%Y",localtime(&T));
        }
        void listCleaner(){
            delete h0,t0;
            h0=NULL;
            t0=NULL;
        }
        void fileLoad(){
            listCleaner();
            ActStructure *k0;
            string something;
            ifstream load;
            load.open("movimientos.txt",ios::in);
            while(getline(load,something)){
                n0=new ActStructure;
                if(h0==NULL){
                    printf("File Loaded!\n");
                    h0=n0;
                    t0=n0;
                    h0->next=NULL;
                    h0->prev=NULL;
                }
                else{
                    k0=t0;
                    t0->next=n0;
                    t0=n0;
                    t0->prev=k0;
                    t0->next=NULL;
                }
                load>>t0->id>>t0->date>>t0->amount>>t0->transactionType>>t0->subTransactionType;
                //cout<<t0->id<<t0->date<<t0->amount<<t0->transactionType<<t0->subTransactionType<<endl;
            }
            load.close();
        }
        void fileUpdate(){
            ActStructure *it0;
            it0=h0;
            ofstream update;
            update.open("movimientos.txt",ios::out);
            while(true){
                if(it0->next==NULL){
                    update<<it0->id<<' '<<it0->date<<' '<<it0->amount<<' '<<it0->transactionType<<' '<<it0->subTransactionType;
                    update.close();
                    break;
                }
                else{
                    update<<it0->id<<' '<<it0->date<<' '<<it0->amount<<' '<<it0->transactionType<<' '<<it0->subTransactionType<<endl;
                    it0=it0->next;
                }
            }
        }
        void stockManagement(){
            prod.fileLoad();
            ProdStructure *it;
            it=h;
            if(h==NULL){
                printf("The file content has not been loaded correctly or list was already empty!\n");
            }
            else{
                printf("Ingresa la clave de un producto para realizar la busqueda: ");
                cin>>matchId;
                while(true){
                    if(it->id==matchId){
                        cout<<"Clave                                          : "<<it->id<<endl;
                        cout<<"Nombre                                         : "<<it->name<<endl;
                        cout<<"Existencia actual(previo al cambio)            : "<<it->currentExistence<<endl;
                        cout<<"Ingrese la cantidad para completar la operacion: ";
                        cin>>acquisition;
                        if(subTransaction=='C' || subTransaction=='D'){
                            it->currentExistence=it->currentExistence+acquisition;
                        }
                        else{
                            it->currentExistence=it->currentExistence-acquisition;
                        }
                        cout<<"Existencia actual(posterior al cambio)         : "<<it->currentExistence<<endl;
                        prod.fileUpdate();
                        activityManagement();
                        break;
                    }
                    else{
                        if(it->next==NULL && matchId!=it->id){
                            printf("El id del producto que buscas no ha sido encontrado.\n");
                            break;
                        }
                        it=it->next;
                    }
                }
            }
            matchId=1000000;
        }
        void activityManagement(){
            fileLoad();
            ActStructure *it0;
            it0=h0;
            if(h0==NULL){
                printf("The file content has not been loaded correctly or list was already empty!\n");
            }
            else{
                while(true){
                    if(it0->next==NULL){
                        printf("Query request successfully sent!\n");
                        ActStructure *n0;
                        n0=new ActStructure;
                        t0=n0;
                        t0->prev=it0;
                        it0->next=t0;
                        t0->next=NULL;
                        dateTime();
                        t0->id=matchId;
                        strcpy(t0->date,dt);
                        t0->amount=acquisition;
                        t0->transactionType=transaction;
                        t0->subTransactionType=subTransaction;
                        fileUpdate();
                        break;
                    }

                }
            }
        }
};

class Report{
    public:
        Product prod;
        char outputMode;
    public:
        void menu(){
            char option;
            while(option!='x'){
                printf("*************************************************************\n");
                printf("***********************MENU DE REPORTES**********************\n");
                printf("*************************************************************\n");
                printf("a)General de productos ordenado por clave\n");
                printf("b)General de productos ordenado por nombre\n");
                printf("c)Productos por familia\n");
                printf("d)Productos a ordenar ordenado por existencia\n");
                printf("e)Productos a ofertar ordenado por existencia\n");
                printf("f)Lista de movimientos de un producto ordenado por fecha\n");
                printf("x)Regresar al menu principal\n");
                printf("Indica la opcion deseada: ");
                cin>>option;
                switch(option){
                    case 'a':
                        system("CLS");
                        sortById();
                        showContent();
                        break;
                    case 'b':
                        sortByName();
                        showContent();
                        break;
                    case 'c':
                        consultFam();
                        break;
                    case 'd':
                        outputMode='d';
                        sortByExistence();
                        showContent();
                        outputMode='o';
                        break;
                    case 'e':
                        outputMode='e';
                        sortByExistence();
                        showContent();
                        outputMode='o';
                        break;
                    case 'f':
                        printf("Funcion no disponoble por el momento");
                        break;
                    case 'x':
                        system("CLS");
                        int main();
                        break;
                    default:
                        printf("La opcion ingresada no es valida!\n");
                        break;
                }
            }
        }
        void showContent(){
            int matchCounter;
            if(h==NULL){
                printf("No hay informacion disponible!\n");
            }
            else{
                ProdStructure *it;
                it=h;
                if(outputMode=='d'){
                    matchCounter=0;
                    printf("%-14s%-33s%-33s%-33s%-14s%-20s%-17s%-17s\n","CLAVE","NOMBRE","FAMILIA","UNIDAD DE MEDIDA","PRECIO","EXISTENCIA ACTUAL","STOCK MINIMO","STOCK MAXIMO");
                    while(true){
                        if(it->currentExistence<=it->minStock){
                            printf("%-14d%-33s%-33s%-33s%-14d%-20d%-17d%-17d\n",it->id,it->name,it->type,it->measureUnit,it->price,it->currentExistence,it->minStock,it->maxStock);
                            matchCounter+=1;
                        }
                        if(it->next==NULL){
                            delete it;
                            break;
                        }
                        it=it->next;
                    }
                    if(matchCounter==0){
                        printf("No hay articulos para ordenar\n");
                    }
                }
                else if(outputMode=='e'){
                    matchCounter=0;
                    printf("%-14s%-33s%-33s%-33s%-14s%-20s%-17s%-17s\n","CLAVE","NOMBRE","FAMILIA","UNIDAD DE MEDIDA","PRECIO","EXISTENCIA ACTUAL","STOCK MINIMO","STOCK MAXIMO");
                    while(true){
                        if(it->currentExistence>=it->maxStock){
                            printf("%-14d%-33s%-33s%-33s%-14d%-20d%-17d%-17d\n",it->id,it->name,it->type,it->measureUnit,it->price,it->currentExistence,it->minStock,it->maxStock);
                            matchCounter+=1;
                        }
                        if(it->next==NULL){
                            delete it;
                            break;
                        }
                        it=it->next;
                    }
                    if(matchCounter==0){
                        printf("No hay articulos para ofertar\n");
                    }
                }
                else{
                    printf("%-14s%-33s%-33s%-33s%-14s%-20s%-17s%-17s\n","CLAVE","NOMBRE","FAMILIA","UNIDAD DE MEDIDA","PRECIO","EXISTENCIA ACTUAL","STOCK MINIMO","STOCK MAXIMO");
                    while(true){
                        printf("%-14d%-33s%-33s%-33s%-14d%-20d%-17d%-17d\n",it->id,it->name,it->type,it->measureUnit,it->price,it->currentExistence,it->minStock,it->maxStock);
                        if(it->next==NULL){
                            delete it;
                            break;
                        }
                        it=it->next;
                    }
                }
            }
        }
        void sortById(){
            prod.fileLoad();
            ProdStructure *i, *j, *aux;
            i=h;
            aux=new ProdStructure;
            while (i!=NULL){
                j=i->next;
                while (j!=NULL){
                    if (i->id > j->id){
                        aux->id=i->id;
                        strcpy(aux->name,i->name);
                        strcpy(aux->type,i->type);
                        strcpy(aux->measureUnit,i->measureUnit);
                        aux->price=i->price;
                        aux->currentExistence=i->currentExistence;
                        aux->minStock=i->minStock;
                        aux->maxStock=i->maxStock;
                        i->id=j->id;
                        strcpy(i->name,j->name);
                        strcpy(i->type,j->type);
                        strcpy(i->measureUnit,j->measureUnit);
                        i->price=j->price;
                        i->currentExistence=j->currentExistence;
                        i->minStock=j->minStock;
                        i->maxStock=j->maxStock;
                        j->id=aux->id;
                        strcpy(j->name,aux->name);
                        strcpy(j->type,aux->type);
                        strcpy(j->measureUnit,aux->measureUnit);
                        j->price=aux->price;
                        j->currentExistence=aux->currentExistence;
                        j->minStock=aux->minStock;
                        j->maxStock=aux->maxStock;
                    }
                    j=j->next;
                }
                i=i->next;
            }
        }
        void sortByName(){
            prod.fileLoad();
            ProdStructure *i, *j, *aux;
            i=h;
            aux=new ProdStructure;
            while (i!=NULL){
                j=i->next;
                while (j!=NULL){
                    if (strcmp(i->name,j->name)==1){
                        aux->id=i->id;
                        strcpy(aux->name,i->name);
                        strcpy(aux->type,i->type);
                        strcpy(aux->measureUnit,i->measureUnit);
                        aux->price=i->price;
                        aux->currentExistence=i->currentExistence;
                        aux->minStock=i->minStock;
                        aux->maxStock=i->maxStock;
                        i->id=j->id;
                        strcpy(i->name,j->name);
                        strcpy(i->type,j->type);
                        strcpy(i->measureUnit,j->measureUnit);
                        i->price=j->price;
                        i->currentExistence=j->currentExistence;
                        i->minStock=j->minStock;
                        i->maxStock=j->maxStock;
                        j->id=aux->id;
                        strcpy(j->name,aux->name);
                        strcpy(j->type,aux->type);
                        strcpy(j->measureUnit,aux->measureUnit);
                        j->price=aux->price;
                        j->currentExistence=aux->currentExistence;
                        j->minStock=aux->minStock;
                        j->maxStock=aux->maxStock;
                    }
                    j=j->next;
                }
                i=i->next;
            }
        }
        void sortByDate(){
            printf("Funcion en desarrollo...\n");
        }
        void consultFam(){
            ProdStructure *it;
            it=h;
            if(h==NULL){
                printf("The file content has not been loaded correctly or was already empty!\n");
            }
            else{
                int matchCount=0;
                char matchFam[21];
                printf("Ingresa la familia del producto para realizar la busqueda: ");
                cin>>matchFam;
                system("CLS");
                cout<<"Familia a consultar: "<<matchFam<<endl;
                while(true){
                    if(strcmp(matchFam,it->type)==0){
                        cout<<"Nombre del producto: "<<it->name<<endl;
                        matchCount++;
                    }
                    else if(it->next==NULL && strcmp(matchFam,it->type)==0 && matchCount==0){
                        cout<<"La categoria " <<matchFam<<" no ha sido encontrada.\n"<<endl;
                        break;
                    }
                    if(it->next==NULL){
                        break;
                    }
                    it=it->next;
                }
            }
        }
        void sortByExistence(){
            prod.fileLoad();
            ProdStructure *x, *y, *aux1;
            x=h;
            aux1=new ProdStructure;
            while (x!=NULL){
                y=x->next;
                while (y!=NULL){
                    if (x->currentExistence > y->currentExistence){
                        aux1->currentExistence=x->currentExistence;
                        strcpy(aux1->name,x->name);
                        strcpy(aux1->type,x->type);
                        strcpy(aux1->measureUnit,x->measureUnit);
                        aux1->price=x->price;
                        aux1->currentExistence=x->currentExistence;
                        aux1->minStock=x->minStock;
                        aux1->maxStock=x->maxStock;
                        x->currentExistence=y->currentExistence;
                        strcpy(x->name,y->name);
                        strcpy(x->type,y->type);
                        strcpy(x->measureUnit,y->measureUnit);
                        x->price=y->price;
                        x->currentExistence=y->currentExistence;
                        x->minStock=y->minStock;
                        x->maxStock=y->maxStock;
                        y->currentExistence=aux1->currentExistence;
                        strcpy(y->name,aux1->name);
                        strcpy(y->type,aux1->type);
                        strcpy(y->measureUnit,aux1->measureUnit);
                        y->price=aux1->price;
                        y->currentExistence=aux1->currentExistence;
                        y->minStock=aux1->minStock;
                        y->maxStock=aux1->maxStock;
                    }
                    y=y->next;
                }
                x=x->next;
            }
        }

};

int main(int argc, const char *argv[]){
    char option;
    while(option!='x'){
        printf("******************************\n");
        printf("**********MENU PRINCIPAL***********\n");
        printf("******************************\n");
        printf("a)Archivo de Productos\n");
        printf("b)Entradas/Salidas de Producto\n");
        printf("c)Reportes\n");
        printf("x)Terminar\n");
        printf("Indica la opcion deseada: ");
        cin>>option;
        switch(option){
            case 'a':
                {
                //Product manager
                Product prod;
                prod.menu();
                break;
                }
            case 'b':
                {
                //Activity manager
                system("CLS");
                Activity actv;
                actv.menu();
                break;
                }
            case 'c':
                {
                //Reports
                system("CLS");
                Report rept;
                rept.menu();
                break;
                }
            case 'x':
                //Exit
                system("EXIT");
                break;
            default:
                system("CLS");
                printf("No valid option has been entered!\n");
                break;
        }
    }
return 0;
}
