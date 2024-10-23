struct tree{
    int info;
    struct tree *esq,*dir;
};typedef struct tree Tree;

Tree *CriaNo(int info){
    Tree *no = (Tree*)malloc(sizeof(Tree));
    no->info = info;
    no->esq = no->dir = NULL;
    return no;
}

void insere(Tree **raiz, int info){
    Tree *aux,*ant;
    if(*raiz == NULL)
        *raiz = CriaNo(info);
    else{
        aux = *raiz;
        while(aux!=NULL){
            ant = aux;
            if(info<aux->info)
                aux=aux->esq;
            else
                aux=aux->dir;
        }
        if(info<ant->info)
            ant->esq=CriaNo(info);
        else
            ant->dir=CriaNo(info);
    }
}