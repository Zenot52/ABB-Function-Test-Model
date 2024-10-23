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

Tree *busca(Tree *raiz,int info){
    while(raiz != NULL && raiz->info!=info)
        if(info<raiz->info)
            raiz = raiz->esq;
        else    
            raiz = raiz->dir;
    return raiz;
}

void pre_ordem(Tree *raiz){
    if(raiz!=NULL){
        printf("%d",raiz->info);
        pre_ordem(raiz->dir);
        pre_ordem(raiz->esq);
    }
}

void in_ordem(Tree *raiz){
    if(raiz!=NULL){
        
        in_ordem(raiz->esq);
        printf("%d",raiz->info);
        in_ordem(raiz->dir);
    }
}

void pos_ordem(Tree *raiz){
    if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d",raiz->info);
    }
}