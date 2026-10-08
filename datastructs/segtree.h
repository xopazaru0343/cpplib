#include "../base_header.h"

struct segtree_sum {
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    segtree_sum(vector<ll> v) : tree(v.size()*4) {vetor = v;}

    //Essa função é direcionada a construção de uma segtree de soma de valores, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    //Por fim, o valor do nó é definido pela soma dos filhos, ou pelo valor correspondente no vetor caso seja uma folha.
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
            value = tree[2*p] + tree[2*p+1];
        }
        tree[p] = value;
    }
    //tl e tr se referem ao mesmo conceito do l e r, so que aplicado a arvore
    ll query(ll p, ll tl, ll tr, ll l, ll r){
        ll value;
        if(l > r) {
            value = 0;            
        }
        else if(l == tl && r == tr){
            value = tree[p];
        }
        else{
            ll tm = (tl+tr) / 2;
            value = query(p*2, tl, tm, l, min(r, tm)) + query(p*2+1, tm+1, tr, max(l, tm+1), r);
        }
        return value;
    }
    void update(ll p, ll tl, ll tr, ll pos, ll new_value){
        ll value;
        if(tl == tr){
            value = new_value;
        } 
        else{
            ll tm = (tl+tr) / 2;
            if(pos <= tm){
                update(p*2, tl, tm, pos, new_value);
            }    
            else{
                update(p*2+1, tm+1, tr, pos, new_value);
            }
            value = tree[p*2] + tree[p*2+1]; 
        }
        tree[p] = value;    
    }

};

struct segtree_max {
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    segtree_max(vector<ll> v) : tree(v.size()*4) {vetor = v;}

    //Essa função é direcionada a construção de uma segtree de buscar o maximo nos segmentos, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    //Por fim, o valor do nó é o menor valor entre os dois filhos, ou pelo valor correspondente no vetor caso seja uma folha.
    void build(ll p, ll l, ll r){
        ll value;
        if(l == r) {
            value = vetor[l];
            if(value == 0) value = -1e17;
        } 
        else {
            //m é o valor intermediario entre o limite inferior e superior, ou seja, entre l e r
            long long m = (l+r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            value = max(tree[2*p], tree[2*p+1]);
        }
        tree[p] = value;
    }
    //tl e tr se referem ao mesmo conceito do l e r, so que aplicado a arvore
    ll query(ll p, ll tl, ll tr, ll l, ll r){
        ll value;
        if(l > r) {
            value = -1e17;
        }
        else if(l == tl && r == tr){
            value = tree[p];
        }
        else{
            ll tm = (tl+tr) / 2;
            value = max(query(p*2, tl, tm, l, min(r, tm)), query(p*2+1, tm+1, tr, max(l, tm+1), r));
        }
        return value;
    }
    void update(ll p, ll tl, ll tr, ll pos, ll new_value){
        ll value;
        if(tl == tr){
            value = new_value;
            if(value == 0) value = -1e17;
        } 
        else{
            ll tm = (tl+tr) / 2;
            if(pos <= tm){
                update(p*2, tl, tm, pos, new_value);
            }    
            else{
                update(p*2+1, tm+1, tr, pos, new_value);
            }
            value = max(tree[p*2], tree[p*2+1]); 
        }
        tree[p] = value;    
    }
};

struct segtree_min {
    //v é o vetor original
    vector<ll> tree;
    vector<ll> vetor;
    segtree_min(vector<ll> v) : tree(v.size()*4) {vetor = v;}

    //Essa função é direcionada a construção de uma segtree de buscar o maximo nos segmentos, construindo os nós via recursão
    //p é a posição atual, l é o limite inferior e r é o limite superior
    //A primeira recursão é direcionada a construir o filho esquerdo do nó que está localizado em 2*p e tem as somas de l até m do nó que chamou a recursão
    //A segunda recursão é direcionada a construir o filho direito do nó que está localizado em 2*p+1 e tem as somas de m+1 até r do nó que chamou a recursão
    //Por fim, o valor do nó é o menor valor entre os dois filhos, ou pelo valor correspondente no vetor caso seja uma folha.
    void build(ll p, ll l, ll r){
        ll value;
        if(l == r) {
            value = vetor[l];
            if(value == 0) value = 1e17;
        } 
        else {
            //m é o valor intermediario entre o limite inferior e superior, ou seja, entre l e r
            long long m = (l+r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            value = min(tree[2*p], tree[2*p+1]);
        }
        tree[p] = value;
    }
    //tl e tr se referem ao mesmo conceito do l e r, so que aplicado a arvore
    ll query(ll p, ll tl, ll tr, ll l, ll r){
        ll value;
        if(l > r) {
            value = 1e17;
        }
        else if(l == tl && r == tr){
            value = tree[p];
        }
        else{
            ll tm = (tl+tr) / 2;
            value = max(query(p*2, tl, tm, l, min(r, tm)), query(p*2+1, tm+1, tr, max(l, tm+1), r));
        }
        return value;
    }
    void update(ll p, ll tl, ll tr, ll pos, ll new_value){
        ll value;
        if(tl == tr){
            value = new_value;
            if(value == 0) value = 1e17;
        } 
        else{
            ll tm = (tl+tr) / 2;
            if(pos <= tm){
                update(p*2, tl, tm, pos, new_value);
            }    
            else{
                update(p*2+1, tm+1, tr, pos, new_value);
            }
            value = min(tree[p*2], tree[p*2+1]); 
        }
        tree[p] = value;    
    }    
};
