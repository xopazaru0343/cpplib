#include "../base_header.h"

struct segtree_lazy_singleupdate {
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    segtree_lazy_singleupdate(vector<ll> v) : tree(v.size()*4) {vetor = v;}

    //Essa função é direcionada a construção de uma segtree lazy, onde a arvore é usada pra adicionar valores em um ponto especifico, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    //Por fim, o valor do nó é definido pela adição dos valores ao segmento.
    void build(ll p, ll l, ll r){
        ll value;
        if(l == r) {
            value = vetor[l];    
        }
        else {
            //m é o valor intermediario entre o limite inferior e superior, ou seja, entre l e r
            long long m = (l+r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            value = 0;
        }
        tree[p] = value;
    }
    //tl e tr se referem ao mesmo conceito do l e r, so que aplicado a arvore
    void update(ll p, ll l, ll r, ll tl, ll tr, ll add){
        ll value;
        if (r > tl && tr > l) { 
            if(l <= tl && tr <= r){
                tree[p] += add;
            }
            else{
                ll tm = (tl+tr) / 2;
                update(p*2, tl, tm, l, r, add);
                update(p*2+1, tm, tr, l, r, add);
            }
        }
    }
    //A função vai passando o valor adicional adiante pros filhos
    ll query(ll p, ll tl, ll tr, ll pos){
        ll value;
        ll tm = (tl+tr)/2;
        if(tr - tl == 1){
            value = tree[p];
        }
        else if(pos <= tm){
            value = tree[p] + query(p*2, tl, tm, pos);
        }
        else{
            value = tree[p] + query(p*2+1, tm, tr, pos);
        }
    }
};

struct segtree_lazy_segmentupdate {
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    vector<ll> lazy;
    segtree_lazy_segmentupdate(vector<ll> v) : tree(v.size()*4), lazy(v.size()*4) {vetor = v;} 
    //Essa função é direcionada a construção de uma segtree lazy, onde a arvore é usada pra adicionar valores em segmentos, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    //Por fim, o valor do nó é definido pela adição dos valores ao segmento.
    void build(ll p, ll l, ll r){
        ll value;
        if(l == r) {
            value = vetor[l];    
        }
        else {
            //m é o valor intermediario entre o limite inferior e superior, ou seja, entre l e r
            long long m = (l+r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            value = 0;
        }
        tree[p] = value;
    }
    //tl e tr se referem ao mesmo conceito do l e r, so que aplicado a arvore
    void refresh(ll p, ll tl, ll tr){
        if(lazy[p] != 0){
            tree[p] += (tr-tl+1)*lazy[p];
        }
        if(tl != tr){
            lazy[p*2] += lazy[p];
            lazy[p*2+1] += lazy[p];
        }
        lazy[p] = 0;
    }

    void update(ll p, ll l, ll r, ll tl, ll tr, ll add){
        refresh(p, tl, tr);
        ll value;
        if (r > tl && tr > l) { 
            if(l <= tl && tr <= r){
                lazy[p] += add;
                refresh(p, tl, tr);
            }
            else{
                ll tm = (tl+tr) / 2;
                update(p*2, tl, tm, l, r, add);
                update(p*2+1, tm, tr, l, r, add);
                tree[p] = tree[2*p] + tree[2*p+1];
            }
        }
    }
    //A função vai passando o valor adicional adiante pros filhos
    ll query(ll p, ll tl, ll tr, ll l, ll r){
        ll value;
        refresh(p, tl, tr);
        ll tm = (tl+tr)/2;
        if (r > tl && tr > l) { 
            if(tr - tl == 1){
                value = tree[p];
            }
            else{
                value = query(p*2, tl, tm, l, r) + query(p*2+1, tm+1, tr, l, r);
            }
        }
        return value;
    }
};




