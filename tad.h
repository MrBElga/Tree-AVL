
struct tree
{
    int info;
    struct tree *esq, *dir;
};
typedef struct tree Tree;

struct pilha
{
    Tree *raiz;
    struct pilha *prox;
};
typedef struct pilha Pilha;

struct fila
{
    Tree *raiz;
    struct fila *prox;
};
typedef struct fila Fila;

int FisEmpty(Fila *inicio)
{
    return inicio == NULL;
}

void initF(Fila **inicio)
{
    *inicio = NULL;
}

void enqueue(Fila **inicio, Tree *raiz)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->raiz = raiz;
    (*inicio)->prox = novo;
}

void dequeue(Fila **inicio, Tree **info)
{
    if (!FisEmpty(*inicio))
    {
        Fila *aux = *inicio;
        *info = (*inicio)->raiz;
        *inicio = (*inicio)->prox;
        free(aux);
    }
    else
    {
        *info = NULL;
    }
}

int isEmpty(Pilha *inicio)
{
    return inicio == NULL;
}

void initP(Pilha **inicio)
{
    *inicio = NULL;
}

void push(Pilha **inicio, Tree *raiz)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->raiz = raiz;
    novo->prox = *inicio;
    *inicio = novo;
}

void pop(Pilha **inicio, Tree **info)
{
    if (!isEmpty(*inicio))
    {
        Pilha *aux = *inicio;
        *info = (*inicio)->raiz;
        *inicio = (*inicio)->prox;
        free(aux);
    }
    else
    {
        *info = NULL;
    }
}

void init(Tree **raiz)
{
    *raiz = NULL;
}

char TreeIsEmpty(Tree *raiz)
{
	return raiz == NULL;
}
// criar nÃƒÂ³
Tree *criaNo(int info)
{
    Tree *no = (Tree *)malloc(sizeof(Tree));
    no->info = info;
    no->esq = no->dir = NULL;
    return no;
}

// localizar nÃƒÂ³
void localizaNo(Tree *raiz, int info, Tree **pai)
{
    if (raiz != NULL)
    {
        if (info == raiz->info)
        {
            *pai = raiz;
        }
        else
        {
            localizaNo(raiz->esq, info, &*pai);
            if (*pai == NULL)
            {
                localizaNo(raiz->dir, info, &*pai);
            }
        }
    }
}



// algoritimos de exibiÃƒÂ§ÃƒÂ£o
void preOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->info);
        preOrd(raiz->esq);
        preOrd(raiz->dir);
    }
}

void inOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        preOrd(raiz->esq);
        printf("%d ", raiz->info);
        preOrd(raiz->dir);
    }
}

void posOrd(Tree *raiz)
{
    if (raiz != NULL)
    {
        preOrd(raiz->esq);
        preOrd(raiz->dir);
        printf("%d ", raiz->info);
    }
}

void deletTree(Tree **raiz)
{
    if (*raiz != NULL)
    {
        deletTree(&(*raiz)->esq);
        deletTree(&(*raiz)->dir);
        free(*raiz);
    }
    *raiz = NULL;
}

// iterativo

void preOrdI(Tree *raiz)
{
    Pilha *P;
    initP(&P);
    push(&P, raiz);
    while (!isEmpty(P))
    {
        if (raiz != NULL)
        {
            pop(&P, &raiz);
            while (raiz != NULL)
            {
                printf("%d ", raiz->info);
                push(&P, raiz);
                raiz = raiz->esq;
            }
        }

        pop(&P, &raiz);
        raiz = raiz->dir;
        if (raiz != NULL)
            push(&P, raiz);
    }
}

void posOrdI(Tree *raiz)
{
    Pilha *P, *P2;
    initP(&P);
    initP(&P2);
    push(&P, raiz);
    while (!isEmpty(P))
    {
        if (raiz != NULL)
        {
            pop(&P, &raiz);
            while (raiz != NULL)
            {
                push(&P, raiz);
                push(&P2, raiz);
                raiz = raiz->esq;
            }
        }

        pop(&P, &raiz);
        raiz = raiz->dir;
        if (raiz != NULL)
            push(&P, raiz);
    }
    while (!isEmpty(P2))
    {
        pop(&P2, &raiz);
        printf("%d ", raiz->info);
    }
}

void BuscaNoI(Tree *raiz, Tree **e, Tree **pai, int info)
{
    *e = *pai = raiz;
    while (*e != NULL && (*e)->info != info)
    {
        *pai = *e;
        if (info < (*e)->info)
        {
            (*e) = (*e)->esq;
        }
        else
        {
            *e = (*e)->dir;
        }
    }
}

Tree *buscaNoR(Tree *raiz, int info)
{
    if (raiz == NULL)
        return NULL;
    if (raiz->info == info)
        return raiz;
    else if (info < raiz->info)
        return buscaNoR(raiz->esq, info);
    else
        return buscaNoR(raiz->dir, info);
}

void exibe(Tree *raiz, int nivel)
{
    int i = 0;
    if (raiz != NULL)
    {
        exibe(raiz->dir, nivel + 1);

        for (i = 0; i < nivel; i++)
        {
            printf("         ");
        }

        if (nivel > 0)
        {
            printf("<-- ");
        }

        printf("(%d)\n", raiz->info);

        exibe(raiz->esq, nivel + 1);
    }
}
//void quantNo(Tree *P, int *qDir)
//{
//}

void rotacaoLL(Tree** raiz)
{
	Tree *q, *temp;
	q = (*raiz)->dir;
	temp = q->esq;
	q->esq = *raiz;
	(*raiz)->dir = temp;
	*raiz = q;
}
void rotacaoRR(Tree** raiz)
{
	Tree *q, *temp;
	q = (*raiz)->esq;
	temp = q->dir;
	q->dir = *raiz;
	(*raiz)->esq = temp;
	*raiz = q;
}

void rotacaoLR(Tree** raiz)
{
	rotacaoLL(&(*raiz));
	rotacaoRR(&(*raiz));
}

void rotacaoRL(Tree** raiz)
{
	rotacaoRR(&(*raiz));
	rotacaoLL(&(*raiz));
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

int getAlt(Tree *folha)
{
 ;
	if(folha == NULL)
		return -1;
	else
    {
       
       
      return 1 +  max( getAlt(folha->esq), getAlt(folha->dir));
    }

}

int fatorBalanceamento(Tree *folha) 
{
	if(!TreeIsEmpty(folha->esq) && !TreeIsEmpty(folha->dir))  
		return getAlt(folha->esq) - getAlt(folha->dir);
	else
		return -1;
}

void insereAVL(Tree** raiz, int info, int* rot)
{
	int fb, fb_filho;
	if(TreeIsEmpty(*raiz))
	{
		*raiz = criaNo(info);
		*rot = 1;
	}
	else
    {
		if(info > (*raiz)->info)
			insereAVL(&(*raiz)->dir, info, &(*rot));
		else
			insereAVL(&(*raiz)->esq, info, &(*rot));
    }
	if(!*rot)
	{
		fb = fatorBalanceamento((*raiz)->dir);
		if ( fb == 2 || fb == -2)
		{
			*rot = 1;
			if(fb == 2)
			{
				fb_filho = fatorBalanceamento((*raiz)->dir) - fatorBalanceamento((*raiz)->esq);
				if(fb_filho == 1) //(2) (1)
					rotacaoLL(&(*raiz));
				else	//(2)(-1)
				{
					rotacaoRR(&(*raiz)->dir);
					rotacaoLL(&(*raiz));
				}
			}
			else	//-2
			{
				fb_filho = fatorBalanceamento((*raiz)->dir) - fatorBalanceamento((*raiz)->esq);
				if(fb_filho == -1) //(-2)(-1)
					rotacaoRR(&(*raiz));
				else
				{
					rotacaoLL(&(*raiz)->esq);
					rotacaoRR(&(*raiz));
				}
			}
		}
	}
}
int calculatealturaIterative(Tree *root)
{

    int altura = -1, tam, levelAt;
    Pilha *P;
    Tree *current;
    initP(&P);
    push(&P, root);

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        while (!isEmpty(P))
        {
            tam = 0;
            levelAt = 1;
            while (tam < levelAt)
            {
                pop(&P, &current);
                if (current->esq != NULL)
                {
                    push(&P, current->esq);
                }
                if (current->dir != NULL)
                {
                    push(&P, current->dir);
                }
                tam++;
            }
            altura++;
        }
        return altura;
    }
}

int CalculaNivel(Tree *raiz, int info, int nivel)
{
    int nivelDireita, nivelEsquerda;
    if (raiz == NULL)
    {
        return -1;
    }
    else if (raiz->info == info)
    {
        return nivel;
    }
    else
    {
        nivelEsquerda = CalculaNivel(raiz->esq, info, nivel + 1);
        if (nivelEsquerda != -1)
        {
            return nivelEsquerda;
        }
        nivelDireita = CalculaNivel(raiz->dir, info, nivel + 1);
        return nivelDireita;
    }
}
