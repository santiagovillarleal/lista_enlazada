#include <stdio.h>
#include <stdlib.h>

typedef struct t_nodo t_nodo;

struct t_nodo{
  int valor;
  t_nodo *sig;
};

#define ERR_OK      0
#define ERR_USO     1
#define ERR_NUM_VAL 2

void print_uso(char *prog)
{
  printf("Uso: %s <VALOR_INICIAL> <NUM_VALORES>\n", prog);
}

void ler_lista(t_nodo *lista)
{
  t_nodo *tmp=lista;
  if(!tmp)
  {
    printf("Lista baleira.\n");
    return;
  }
  printf(" %d", tmp->valor);
  while (tmp)
  {
    tmp=tmp->sig;
    if (tmp) printf(", %d", tmp->valor);
  }
  printf("\n");
}

t_nodo *crear_nodo(int valor)
{
  t_nodo *novo=(t_nodo *)malloc(sizeof(t_nodo));
  novo->valor=valor;
  novo->sig=NULL;
  return novo;
}

void insertar_valor(t_nodo **lista, int valor)
{
  t_nodo *p_lista = *lista;
  if (!p_lista)
  {
    p_lista=crear_nodo(valor);
    *lista=p_lista;
    return;
  }

  t_nodo *tmp=p_lista;
  while (tmp->sig)
  {
    tmp=tmp->sig;
  }
  tmp->sig=crear_nodo(valor);
}

void invertir_lista(t_nodo **lista)
{
  t_nodo *p_lista=*lista, *nodo_sig=NULL, *nodo_tmp=NULL;
  if (!p_lista) return;

  nodo_sig=p_lista->sig;
  p_lista->sig=NULL;

  while (nodo_sig)
  {
    nodo_tmp=nodo_sig->sig;
    nodo_sig->sig=p_lista;
    p_lista=nodo_sig;
    nodo_sig=nodo_tmp;
  }
  *lista=p_lista;
}

void borrar_lista(t_nodo **lista)
{
  t_nodo *p_lista=*lista, *p_sig=NULL;
  if (!p_lista) return;

  while (p_lista)
  {
    p_sig=p_lista->sig;
    free(p_lista);
    p_lista=p_sig;
  }
  *lista=NULL;
}

int main(int argc, char *argv[])
{
  t_nodo *INI=NULL;
  int valor_ini, num_valores, valor_max;

  valor_ini=num_valores=valor_max=0;
  if (argc!=3)
  {
    print_uso(argv[0]);
    exit(ERR_USO);
  }

  valor_ini=atoi(argv[1]);
  num_valores=atoi(argv[2]);
  if (num_valores<0)
  {
    printf("O número de elementos da lista non pode ser negativo.\n");
    exit(ERR_NUM_VAL);
  }
  valor_max=valor_ini+num_valores-1;

  for (int i=valor_ini;i<=valor_max;i++)
  {
    insertar_valor(&INI, i);
  }
  printf("Contido da lista creada:\n");
  ler_lista(INI);

  invertir_lista(&INI);
  printf("Contido da lista invertida:\n");
  ler_lista(INI);

  borrar_lista(&INI);
  printf("Contido da lista borrada:\n");
  ler_lista(INI);

  return ERR_OK;
}
