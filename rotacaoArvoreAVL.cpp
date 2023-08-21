#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height; // Altura da subárvore enraizada neste nó
};

// Função para calcular a altura de um nó
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Função para calcular o fator de equilíbrio de um nó
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função para atualizar a altura de um nó com base na altura de seus filhos
void updateHeight(Node* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Função para fazer uma rotação simples à esquerda (LL)
Node* rotateLeft(Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    // Realiza a rotação
    x->left = y;
    y->right = T2;

    // Atualiza as alturas dos nós afetados
    updateHeight(y);
    updateHeight(x);

    // Retorna o novo nó raiz
    return x;
}

// Função para inserir um nó em uma árvore AVL
Node* insert(Node* root, int data) {
    // Insira o nó como em uma árvore binária de busca normal
    if (root == nullptr) {
        return new Node{data, nullptr, nullptr, 1};
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root; // Ignora valores duplicados
    }

    // Atualiza a altura deste nó
    updateHeight(root);

    // Calcula o fator de equilíbrio deste nó
    int balance = getBalanceFactor(root);

    // Verifica o balanceamento e realiza rotações, se necessário
    if (balance > 1 && data < root->left->data) {
        return rotateRight(root);
    }
    if (balance < -1 && data > root->right->data) {
        return rotateLeft(root);
    }

    // ...
    // Lógica para outros casos de balanceamento aqui

    // Retorna o nó raiz
    return root;
}

int main() {
    Node* root = nullptr;
    // Insira valores na árvore AVL usando a função 'insert'
    return 0;
}
