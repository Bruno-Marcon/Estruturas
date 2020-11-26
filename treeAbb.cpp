#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *right; 
    struct node *left; 
}Node;

Node* searchNode(Node*, int);
Node* find_minimum(Node*);
Node* createNode(int);
Node* insert(Node*, int);
Node* deleteNode(Node*, int);
void postorder(Node*);
void order(Node *node);
void preorder(Node *node);

Node* find_node(Node *node, int data){

	if(node == NULL){
		return NULL;
	}
	if(data < node->data){
		return find_node(node->left, data);
	}else if(data > node->data){
		return find_node(node->right, data);
	}	
	return node;
}
Node* find_minimum(Node *root)
{
    if(root == NULL){
        return NULL;
    }else if(root->left != NULL){ 
        return find_minimum(root->left);
    return root;
	}
}
Node* createNode(int aux)
{
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->data = aux;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* insert(Node *root, int aux)
{	
	if(root==NULL){
		createNode(aux);
	}else{
		for(;;){
		    if(aux>root->data){ 
		        root->right = insert(root->right, aux);
		    }else{ 
		        root->left = insert(root->left,aux);
		    return root;
			}
		}
	}	
}
Node* deleteNode(Node *root, int aux)
{
    if(root==NULL){
	}
        return NULL;
    }
	
	if (aux>root->data){
        root->right = deleteNode(root->right, aux);
    }
	
	else if(aux<root->data){
        root->left = deleteNode(root->left, aux);
    }
	
	else{
        
		if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
		else if(root->left==NULL || root->right==NULL){
            Node *auxTemp;
            
			if(root->left==NULL){
                auxTemp = root->right;
            }
			else{
                auxTemp = root->left;
            	free(root);
            return auxTemp;
        	}
			{
	            Node *auxTemp= find_minimum(root->right);
	            root->data = auxTemp->data;
	            root->right = deleteNode(root->right, auxTemp->data);
			}
    		return root;
    	}
    }
    free(root);
}
void preorder(Node *node){
	if(node != NULL){
		printf("%i ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void order(Node *node){
	if(node != NULL){
		order(node->left);
		printf("%i ", node->data);
		order(node->right);
	}
}

void postorder(Node *node){
	if(node != NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%i ", node->data);
	}
}
int main(){
	int op, num;
	Node* root;
	
	for(;;){
		printf("\nO que deseja fazer?\n1 - Inserir \n2 - pesquisar \n3 - Remover \n4 - Mostrar todos\n5 - Sair\n");
		scanf("%i",&op);
			
		if(op==1){
			printf("Digite o ISSN/ISBN que deseja inserir\n");
			scanf("%i", &num);
			insert(root, num);
		}else if(op==2){
			printf("Digite o ISSN/ISBN que deseja pesquisar\n");
			scanf("%i", &num);
			find_node(root, num);
			if(root==NULL){
				printf("O ISSN/ISBN não foi encontrado\n");
			}else{
				printf("ISSN/ISBN: %i\n", root->data);
			}
		}else if(op==3){
			printf("Digite o ISSN/ISBN que deseja remover\n");
			scanf("%i", &num);
			find_node(root, num);
			if(root == NULL){
				printf("O ISSN/ISBN não foi encontrado para ser feita a remoção\n");
			}else{
				deleteNode(root, num);
			}
		}else if(op==4){
			printf("\nEm Ordem... ");
 			order(root);
			printf("\nPre Ordem... ");
			preorder(root);
			printf("\nPos Ordem... ");
			postorder(root);
		}else if(op==5){
			printf("Escolha outra opção\nEscolha outra opção\nEscolha outra opção\n");
		}
	}
}
