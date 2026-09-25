#include "../baseheader.h"

struct segtree {
    //O build é vazio de maneira a delegar as funções qual a finalidade da segtree em si
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    segtree(vector<ll> v) : tree(v.size()*4) {vetor = v;}

    //Essa função é direcionada a construção de uma segtree de soma de valores, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    void build_sum(ll p, ll l, ll r){
        if(l == r) {
            tree[p] = vetor[l];
        } else {
            //m é o valor intermediario entre o limite inferior e superior, ou seja, entre l e r
            long long m = (l+r) / 2;
            build_sum(2*p, l, m);
            build_sum(2*p+1, m+1, r);
            tree[p] = tree[2+p] + tree[2*p+1];
        }
    }
};
