Ham init_graph
void init_graph(Graph *pG,int n){
    pG->n=n;
    pG->m=0;
}


Ham add_edge
void add_edge(Graph *pG, int u, int v) {
    pG->edges[pG->m].u=u;
    pG->edges[pG->m].v=v;
    pG->m++;
}


Ham add_edge nang cao
void add_edge(Graph *pG, int u, int v) {
    // Kiểm tra tính hợp lệ của đỉnh u và v
    if (u < 1 || u > pG->n || v < 1 || v > pG->n) {
        return; // Không hợp lệ, bỏ qua
    }
    // Thêm cung (u, v) vào danh sách edges nếu còn chỗ
    if (pG->m < MAX_M) {
        pG->edges[pG->m].u = u;
        pG->edges[pG->m].v = v;
        pG->m++;
    }
}
-------
void add_edge(Graph *pG, int u, int v) {
    int e;
    int check = 0;
    for (e = 0;  e <= pG->m; e++){
        if (pG->edges[e].u==u && pG->edges[e].v==v ){
            check = 1;
        }
    }
    if (check == 0) {
    pG->edges[pG->m].u=u;
    pG->edges[pG->m].v=v;
    pG->m++; }
    
}
-------
void add_edge(Graph *pG, int u, int v) {
    int e;
    int check = 0;
    for (e = 0;  e <= pG->m; e++){
        if ((pG->edges[e].u==v && pG->edges[e].v==u) || (u==v)){
            check = 1;
        }
    }
    if (check == 0) {
    pG->edges[pG->m].u=u;
    pG->edges[pG->m].v=v;
    pG->m++; }
    
}


Ham adjacent
int adjacent(Graph *pG, int u, int v){
    int e;
    for(e=0; e <pG->m;e++){
        if((pG->edges[e].u==u && pG->edges[e].v==v) || (pG->edges[e].u==v && pG->edges[e].v==u)){
            return 1;
        }
    }
    return 0;
}
---------
int adjacent(Graph *pG, int u, int v) {
    int e;
    for(e=0; e < pG->m;e++){
        if(pG->edges[e].u==u &&pG->edges[e].v==v){
            return 1;
        }
    }
    return 0;
}
--------
Bai tap tinh bac DS cung
typedef struct{
    int u,v;
}Edge;
typedef struct {
    int n,m;
    Edge edges[100];
}Graph;


void init_graph (Graph* G,int n){
    G->n = n;
    G->m= 0;
}
void add_edge(Graph *G, int u, int v){
    G->edges[G->m].u=u;
    G->edges[G->m].v=v;
    G->m++;
}
int degree(Graph *G, int u){
    int e, dem = 0;
    for (e=0; e < G->m; e++){
        if(G->edges[e].u==u){
            dem++;
        }
        if(G->edges[e].v==u){
            dem++;
        }
        
    } 
    return dem;
}
---------------------------------------------------------------------------------------------------
#include <stdio.h>
typedef struct {
	int u,v;
}Edge;
typedef struct {
	int n,m;
	Edge edges[100];
}Graph;
void init_graph(Graph *G, int n) {
	G->n=n;
	G -> m=0;
}
void add_edge(Graph *G, int u, int v){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
	G->m++;
}
int deg (Graph *G, int u){
	int e, dem=0;
	for ( e = 0; e < G->m;e++){
		if(G->edges[e].u==u){
		
			dem++;}
			
		if(G->edges[e].v==u){
		
			dem++;}
	}
	return dem;
}
int main(){
	Graph H;
	int n,m;
	scanf("%d %d",&n, &m);
	init_graph(&H,n);
	int i;
	for ( i = 1; i <= m;i++ ){
		int n,m;
		scanf("%d %d",&n,&m);
		add_edge(&H,n,m);
	}
	for (i = 1; i <= n; i++){
		printf ("deg(%d) = %d\n",i, deg(&H,i));
	}
}
------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_N 100

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int degree(Graph G, int u){
    int deg_u = 0;
    for(int i = 0; i < G.m; i++){
        if(G.edges[i].u == u)
            deg_u++;
        if(G.edges[i].v == u)
            deg_u++;
    }
    return deg_u;
}

int main(){
    freopen("dt.txt", "r", stdin);
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 0; e < m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg(%d) = %d\n", u, degree(G, u));
    return 0;
}
---------------------------------------------------------------------------------------------------


Liet ke dinh ke
#include <stdio.h>

#define MAX_N 100

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int adjacent(Graph *pG, int u, int v){
    for(int i = 0; i < pG->m; i++)
        if((pG->edges[i].u == u && pG->edges[i].v == v)
        || (pG->edges[i].u == v && pG->edges[i].v == u)) return 1;
    return 0;
}

void neighbours(Graph *pG, int u){
    for(int v = 1; v <= pG->n; v++)
        if(adjacent(pG, u, v))
            printf("%d ", v);
    printf("\n");
}

int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 0; e < m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++){
        printf("neighbours(%d) = ", u);
        neighbours(&G, u);
    }    
    return 0;
}
-----------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_N 100

typedef struct{
    int u, v;
}Edge;

typedef struct{
    int n, m;
    Edge edges[MAX_N];
}Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}

int adjacent(Graph *pG, int u, int v){
    for(int i = 0; i < pG->m; i++)
        if((pG->edges[i].u == u && pG->edges[i].v == v)) return 1;
    return 0;
}

void neighbours(Graph *pG, int u){
    for(int v = 1; v <= pG->n; v++)
        if(adjacent(pG, u, v))
            printf("%d ", v);
    printf("\n");
}

int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int e = 0; e < m; e++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++){
        printf("neighbours(%d) = ", u);
        neighbours(&G, u);
    }    
    return 0;
}
-------------------------------------------------------------------------------------------------




Ma tran ke
void init_graph (Graph *G,int n){
	int i,j;
	G->n=n;
	G->m=0;
	for(i = 1; i <=n;i++){
		for( j = 1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge (Graph *G,int n, int m){
		G->A[n][m]=1;
		G->A[m][n]=1;
		G->m++;		
}
-------------------------------------------------------------------------------------------------
void init_graph (Graph *G,int n){
	int i,j;
	G->n=n;
	G->m=0;
	for(i = 1; i <=n;i++){
		for( j = 1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge (Graph *G,int n, int m){
    if(G->A[n][m] >= 1 && G->A[m][n]>=1){
        G->A[n][m]++;
		if (m != n){
		
		G->A[m][n]++;}
		G->m++;	
    }
    else{
		G->A[n][m]=1;
		G->A[m][n]=1;
		G->m++;	}	
}
-------------------------------------------------------------------------------------------------
void init_graph (Graph *G,int n){
	int i,j;
	G->n=n;
	G->m=0;
	for(i = 1; i <=n;i++){
		for( j = 1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge (Graph *G,int n, int m){
    if(G->A[n][m] >= 1 || G->A[m][n]>=1){
        G->A[n][m]++;
	
		G->m++;	
    }
    else{
		G->A[n][m]=1;
	
		G->m++;	}	
}




Ham add_edge ma tran ke
void add_edge (Graph *G,int n, int m){
		G->A[n][m]=1;
		G->A[m][n]=1;
		G->m++;		
}
-------------------------------------------------------------------------------------------------
void add_edge (Graph *G,int n, int m){
		G->A[n][m]=1;
		
		G->m++;		
}
-------------------------------------------------------------------------------------------------
void add_edge (Graph *G,int n, int m){
    if(G->A[n][m] >= 1 && G->A[m][n]>=1){
        G->A[n][m]++;
        if(m!=n){
        G->A[m][n]++;}
		G->m++;	
    } else {
		G->A[n][m]=1;
		G->A[m][n]=1;
		G->m++;	}	
}
-------------------------------------------------------------------------------------------------
void add_edge (Graph *G,int n, int m){
    if(G->A[n][m] >= 1 || G->A[m][n]>=1){
        G->A[n][m]++;
        
		G->m++;	
    } else {
		G->A[n][m]=1;
	
		G->m++;	}	
}
-------------------------------------------------------------------------------------------------



in ma tran ke
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->A[v][u]++;
    pG->m++;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
-----------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v] = 1;
    pG->m++;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
----------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    if(u != v)
        pG->A[v][u]++;
    pG->m++;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
---------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->m++;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printf("Ma tran ke:\n");
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
----------------------------------------------------------------------------------------




Ham tinh bac ma tran ke
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    if(u != v)
        pG->A[v][u]++;
    pG->m++;
}

int degree(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v];
    
    return deg_u + pG->A[u][u];
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg(%d) = %d\n",u, degree(&G, u));
    return 0;
}
-----------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->m++;
}

int degree(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v] + pG->A[v][u];
    
    return deg_u;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg(%d) = %d\n",u, degree(&G, u));
    return 0;
}
-----------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->m++;
}

int indegree(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[v][u];
    
    return deg_u;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg_in(%d) = %d\n",u, indegree(&G, u));
    return 0;
}
----------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->m++;
}

int outdegree(Graph *pG, int u){
    int deg_u = 0;
    for(int v = 1; v <= pG->n; v++)
        deg_u += pG->A[u][v];
    
    return deg_u;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++)
        printf("deg_out(%d) = %d\n",u, outdegree(&G, u));
    return 0;
}
-------------------------------------------------------------------------------------------------------------



Liet ke dinh ke ma tran ke
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    if(u != v)
        pG->A[v][u]++;
    pG->m++;
}

void neighbours(Graph G, int u){
    for(int v = 1; v <= G.n; v++){
        if(G.A[u][v] > 0)
            printf("%d ", v);
    }
    printf("\n");
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++){
        printf("neighbours(%d) = ",u);
        neighbours(G, u);
    }
    return 0;
}
--------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;

    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v){
    pG->A[u][v]++;
    pG->m++;
}

void neighbours(Graph G, int u){
    for(int v = 1; v <= G.n; v++){
        if(G.A[u][v] > 0)
            printf("%d ", v);
    }
    printf("\n");
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for(int u = 1; u <= G.n; u++){
        printf("neighbours(%d) = ",u);
        neighbours(G, u);
    }
    return 0;
}
------------------------------------------------------------------------------------------------



chuyen doi giua cac pp bieu dien
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            scanf("%d", &G.A[u][v]);

    for(int u = 1; u <= n; u++)
        for(int v = u; v <= n; v++){
            for(int i = 0; i < G.A[u][v]; i++)
                printf("%d %d\n", u, v);
        }
    return 0;
}
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            scanf("%d", &G.A[u][v]);

    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++){
            for(int i = 0; i < G.A[u][v]; i++)
                printf("%d %d\n", u, v);
        }
    return 0;
}
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            scanf("%d", &G.A[u][v]);

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            for(int i = 0; i < G.A[u][v]; i++)
                printf("%d ", v);
        }
        printf("0\n");
    }
    return 0;
}
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            scanf("%d", &G.A[u][v]);

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            for(int i = 0; i < G.A[u][v]; i++)
                printf("%d ", v);
        }
        printf("0\n");
    }
    return 0;
}
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n);
    for(int u = 1; u <= n; u++){
        int v;
        do{
            scanf("%d", &v);
            G.A[u][v]++;
        }while(v != 0);
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    return 0;
}
-------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

int main() {
    int n;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n);
    for(int u = 1; u <= n; u++){
        int v;
        do{
            scanf("%d", &v);
            G.A[u][v]++;
        }while(v != 0);
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    return 0;
}




bfs tu 1 dinh
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	BFS(&G, 1);
	return 0;
}
----------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	BFS(&G, 1);
	return 0;
}
------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m, s;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	scanf("%d", &s);
	BFS(&G, s);
	return 0;
}
---------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m, s;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	scanf("%d", &s);
	BFS(&G, s);
	return 0;
}
----------------------------------------------------------------------------------------------------------


bfs toan bo do thi
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			BFS(&G, u);
	return 0;
}
---------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, int u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

int front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void BFS(Graph* pG, int u) {
	queue Q;
	make_null_queue(&Q);
	enqueue(&Q, u);
	while (!empty(Q)) {
		int s = front(Q);
		dequeue(&Q);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, s, v))
				enqueue(&Q, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			BFS(&G, u);
	return 0;
}
----------------------------------------------------------------------------------------------



dfs tu 1 dinh

#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;


	DFS(&G, 1);
	return 0;
}
-------------------------------------------------------------------------------------

#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;


	DFS(&G, 1);
	return 0;
}
------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;
	int s;
	scanf("%d", &s);
	DFS(&G, s);
	return 0;
}
-----------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;
	int s;
	scanf("%d", &s);
	DFS(&G, s);
	return 0;
}
--------------------------------------------------------------------------------------------------------------


dfs toan bo do thi
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;
	for (int u = 1; u <= n; u++) 
		if (mark[u] == 0)
			DFS(&G, u);
	return 0;
}
-------------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, int x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

int back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int u) {
	stack S;
	make_null_stack(&S);

	push_back(&S, u);

	while (!empty(S)) {
		int s = back(S);
		pop_back(&S);
		if (mark[s] != 0)
			continue;

		printf("%d\n", s);
		mark[s] = 1;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, s, v))
				push_back(&S, v);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++)
		mark[u] = 0;
	for (int u = 1; u <= n; u++) 
		if (mark[u] == 0)
			DFS(&G, u);
	return 0;
}
----------------------------------------------------------------------------------------------



cay duyet do thi
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, p;
}elementype;

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	elementype data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, elementype u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

elementype front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];
int parent[MAX];

void BFS(Graph* pG, int s) {
	queue Q;
	make_null_queue(&Q);
	elementype pair;
	pair.u = s; pair.p = -1;
	enqueue(&Q, pair);
	while (!empty(Q)) {
    	elementype pair = front(Q); dequeue(&Q);
		int u = pair.u, p = pair.p;
		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, u, v)) {
				elementype pair = { v, u };
				enqueue(&Q, pair);
			}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
		parent[u] = -1;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			BFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
-----------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, p;
}elementype;

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	elementype data[MAX];
	int front, rear;
}queue;

void make_null_queue(queue* pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(queue* pQ, elementype u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

void dequeue(queue* pQ) {
	pQ->front++;
}

elementype front(queue Q) {
	return Q.data[Q.front];
}

int empty(queue Q) {
	return Q.front > Q.rear;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];
int parent[MAX];

void BFS(Graph* pG, int s) {
	queue Q;
	make_null_queue(&Q);
	elementype pair;
	pair.u = s; pair.p = -1;
	enqueue(&Q, pair);
	while (!empty(Q)) {
    	elementype pair = front(Q); dequeue(&Q);
		int u = pair.u, p = pair.p;
		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;

		for (int v = 1; v <= pG->n; v++)
			if (adjacent(pG, u, v)) {
				elementype pair = { v, u };
				enqueue(&Q, pair);
			}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
		parent[u] = -1;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			BFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int u, p;
}elementtype;

typedef struct {
	elementtype data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, elementtype x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

elementtype back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];
int parent[MAX];
void DFS(Graph* pG, int s) {
	stack S;
	make_null_stack(&S);
	elementtype pair = { s, -1 };
	push_back(&S, pair);

	while (!empty(S)) {
		elementtype pair = back(S);
		pop_back(&S);

		int u = pair.u, p = pair.p;

		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, u, v)) {
				elementtype pair = { v, u };
				push_back(&S, pair);
			}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
		parent[u] = -1;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			DFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
---------------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

typedef struct {
	int u, p;
}elementtype;

typedef struct {
	elementtype data[MAX];
	int top_id;
}stack;

void make_null_stack(stack* pS) {
	pS->top_id = -1;
}

void push_back(stack* pS, elementtype x) {
	pS->top_id++;
	pS->data[pS->top_id] = x;
}

void pop_back(stack* pS) {
	pS->top_id--;
}

elementtype back(stack S) {
	return S.data[S.top_id];
}

int empty(stack S) {
	return S.top_id == -1;
}

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u && pG->edges[e].v == v)
			return 1;
	return 0;
}

int mark[MAX];
int parent[MAX];
void DFS(Graph* pG, int s) {
	stack S;
	make_null_stack(&S);
	elementtype pair = { s, -1 };
	push_back(&S, pair);

	while (!empty(S)) {
		elementtype pair = back(S);
		pop_back(&S);

		int u = pair.u, p = pair.p;

		if (mark[u] != 0)
			continue;

		mark[u] = 1;
		parent[u] = p;
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, u, v)) {
				elementtype pair = { v, u };
				push_back(&S, pair);
			}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
		parent[u] = -1;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0)
			DFS(&G, u);

	for (int u = 1; u <= n; u++)
		printf("%d %d\n", u, parent[u]);
	return 0;
}
---------------------------------------------------------------------------------------------------------


kiem tra lien thong
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int connected(Graph G) {
	for (int u = 1; u <= G.n; u++)
		if (mark[u] == 0)
			return 0; 	

	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}

	DFS(&G, 1);

	if (connected(G))
		printf("CONNECTED");
	else
		printf("DISCONNECTED");

	return 0;
}
----------------------------------------------------------------------------------------------


bo phan lien thong
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}

	int count = 0;

	for (int u = 1; u <= n; u++) {
		if (mark[u] == 0) {
			count++;
			DFS(&G, u);
		}
	}

	printf("%d", count);

	return 0;
}
-------------------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}

	int count = 0;

	DFS(&G, 1);

	for (int u = 1; u <= n; u++)
		if (mark[u] != 0)
			count++;

	printf("%d", count);

	return 0;
}
-------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	int s;
	scanf("%d", &s);

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}

	int count = 0;

	DFS(&G, s);

	for (int u = 1; u <= n; u++)
		if (mark[u] != 0)
			count++;

	printf("%d", count);

	return 0;
}
----------------------------------------------------------------------------------------------
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];
int max_cnt = 0, tmp_cnt = 0;

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	tmp_cnt++;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}

	for (int u = 1; u <= n; u++)
		if (mark[u] == 0) {
			tmp_cnt = 0;
			DFS(&G, u);
			if (tmp_cnt > max_cnt) max_cnt = tmp_cnt;
		}

	printf("%d", max_cnt);

	return 0;
}
----------------------------------------------------------------------------------------------------------


hon dao
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int connect(Graph G) {
	for (int u = 1; u <= G.n; u++)
		if (mark[u] == 0) return 0;
	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}
	DFS(&G, 1);

	if (connect(G) == 1) printf("YES");
	else printf("NO");

	return 0;
}
--------------------------------------------------------------------------------------------------
ton ngo khong
#include <stdio.h>
#define MAX 100

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int mark[MAX];

void DFS(Graph* pG, int s) {
	mark[s] = 1;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v) && mark[v] == 0)
			DFS(pG, v);
}

int connect(Graph G) {
	for (int u = 1; u <= G.n; u++)
		if (mark[u] == 0) return 0;
	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		mark[u] = 0;
	}
	DFS(&G, 1);

	if (connect(G) == 1) printf("DUOC");
	else printf("KHONG");

	return 0;
}
-------------------------------------------------------------------------------------------------


kiem tra chu trinh
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int color[MAX];
int has_circle;

void DFS(Graph* pG, int s) {
	color[s] = GRAY;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (color[v] == WHITE)
				DFS(pG, v);
			else if (color[v] == GRAY) {
				has_circle = 1;
				return;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE)
			DFS(&G, u);
	}
	if (has_circle == 1) printf("CIRCLED");
	else printf("NO CIRCLE");

	return 0;
}
-----------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int parent[MAX];
int color[MAX];
int has_circle;

int start, end;

void DFS(Graph* pG, int s, int p) {
	color[s] = GRAY;
	parent[s] = p;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (color[v] == WHITE)
				DFS(pG, v, s);
			else if (color[v] == GRAY) {
				has_circle = 1;
				start = s;
				end = v;
				return;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
		parent[u] = -1;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			DFS(&G, u, -1);
		}
	}
	if (has_circle == 1) {
		int A[MAX], i = 0;
		A[0] = start;
		int u = start, v = end;
		do {
			u = parent[u];
			i++;
			A[i] = u;
		} while (u != v);

		for (int j = i; j >= 0; j--)
			printf("%d ", A[j]);

		printf("%d\n", A[i]);
	}
	else printf("-1");

	return 0;
}
----------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int color[MAX];
int has_circle;

void DFS(Graph* pG, int s, int p) {
	color[s] = GRAY;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (v == p) continue;
			if (color[v] == WHITE)
				DFS(pG, v, s);
			else if (color[v] == GRAY) {
				has_circle = 1;
				return;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE)
			DFS(&G, u, -1);
	}
	if (has_circle == 1) printf("CIRCLED");
	else printf("NO CIRCLE");

	return 0;
}
---------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int parent[MAX];
int color[MAX];
int has_circle;

int start, end;

void DFS(Graph* pG, int s, int p) {
	color[s] = GRAY;
	parent[s] = p;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (v == p) continue;
			if (color[v] == WHITE)
				DFS(pG, v, s);
			else if (color[v] == GRAY) {
				has_circle = 1;
				start = s;
				end = v;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
		parent[u] = -1;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			DFS(&G, u, -1);
		}
	}
	if (has_circle == 1) {
		int A[MAX], i = 0;
		A[0] = start;
		int u = start, v = end;
		do {
			u = parent[u];
			i++;
			A[i] = u;
		} while (u != v);

		for (int j = i; j >= 0; j--)
			printf("%d ", A[j]);

		printf("%d\n", A[i]);
	}
	else printf("-1");

	return 0;
}
--------------------------------------------------------------------------------------------------


Ung dung chu trinh
excel
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int parent[MAX];
int color[MAX];
int has_circle;

int start, end;

void DFS(Graph* pG, int s) {
	color[s] = GRAY;

	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (color[v] == WHITE)
				DFS(pG, v);
			else if (color[v] == GRAY) {
				has_circle = 1;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
		parent[u] = -1;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			DFS(&G, u);
		}
	}
	if (has_circle == 1) {
		printf("CIRCULAR REFERENCE");
	}
	else printf("OK");

	return 0;
}
------------------------------------------------------------------------------------------
haddock
#include <stdio.h>

#define MAX 100

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int parent[MAX];
int color[MAX];
int has_circle;

int start, end;

void DFS(Graph* pG, int s, int p) {
	color[s] = GRAY;
	parent[s] = p;
	for (int v = 1; v <= pG->n; v++)
		if (adjacent(pG, s, v)) {
			if (color[v] == WHITE)
				DFS(pG, v, s);
			else if (color[v] == GRAY) {
				has_circle = 1;
			}
		}
	color[s] = BLACK;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = WHITE;
		parent[u] = -1;
	}

	has_circle = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == WHITE) {
			DFS(&G, u, -1);
		}
	}
	if (has_circle == 1) {
		printf("NO");
	}
	else printf("YES");

	return 0;
}
--------------------------------------------------------------------------------------------------------


do thi phan doi
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int color[MAX];
int conflict;

void colorize(Graph* pG, int u, int c) {
	color[u] = c;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (color[v] == NO_COLOR)
				colorize(pG, v, 3 - c);
			else if (color[v] == color[u])
				conflict = 1;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = NO_COLOR;
	}
	conflict = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == NO_COLOR) {
			colorize(&G, u, BLUE);
		}
	}

	if (conflict == 1) {
		printf("NO");
	}
	else printf("YES");

	return 0;
}
-----------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v)
			|| (pG->edges[e].u == v && pG->edges[e].v == u))
			return 1;
	return 0;
}

int color[MAX];
int conflict;

void colorize(Graph* pG, int u, int c) {
	color[u] = c;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (color[v] == NO_COLOR)
				colorize(pG, v, 3 - c);
			else if (color[v] == color[u])
				conflict = 1;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}

	for (int u = 1; u <= n; u++) {
		color[u] = NO_COLOR;
	}
	conflict = 0;
	for (int u = 1; u <= n; u++) {
		if (color[u] == NO_COLOR) {
			colorize(&G, u, BLUE);
		}
	}

	if (conflict == 1) {
		printf("IMPOSSIBLE");
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (color[i] == BLUE) printf("%d ", i);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			if (color[i] == RED) printf("%d ", i);
		}
	}

	return 0;
}
--------------------------------------------------------------------------------------------------------------


Tarjan
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (int u = 1; u <= G.n; u++)
		num[u] = -1;

	k = 1;
	make_null_stack(&S);

	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1)
			SCC(&G, u);

	for (int u = 1; u <= G.n; u++)
		printf("%d %d\n", num[u], min_num[u]);

	return 0;
}
-------------------------------------------------------------------------------------------------
lien thong manh

#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int cnt = 0;
int strong_connect = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		cnt++;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	if (cnt == 1) printf("STRONG CONNECTED");
	else printf("DISCONNECTED");

	return 0;
}
--------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int cnt = 0;
int strong_connect = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		cnt++;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	printf("%d", cnt);

	return 0;
}
----------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int max_cnt = 0;
int strong_connect = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		int tmp_cnt = 0;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
			tmp_cnt++;
		} while (w != u);
		max_cnt = max(max_cnt, tmp_cnt);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	printf("%d", max_cnt);

	return 0;
}
---------------------------------------------------------------------------------------------------------------


come and go
#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int p) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
	if (p == 2) {
		pG->edges[pG->m].u = v;
		pG->edges[pG->m].v = u;
		pG->m++;
	}
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int cnt = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		cnt++;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, p;
		scanf("%d %d %d", &u, &v, &p);
		add_edge(&G, u, v, p);
	}
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	if (cnt == 1) printf("OKIE");
	else printf("NO");
	return 0;
}
----------------------------------------------------------------------------------------------------------------
Trust group



#include <stdio.h>

#define MAX 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

typedef struct {
	int data[MAX];
	int topindex;
}Stack;

void make_null_stack(Stack* pS) {
	pS->topindex = -1;
}

void push_back(Stack* pS, int u) {
	pS->topindex++;
	pS->data[pS->topindex] = u;
}

void pop_back(Stack* pS) {
	pS->topindex--;
}

int top(Stack* pS) {
	return pS->data[pS->topindex];
}

int empty(Stack* pS) {
	return pS->topindex == -1;
}

typedef struct {
	int u, v;
}Edge;

typedef struct {
	int n, m;
	Edge edges[MAX];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int adjacent(Graph* pG, int u, int v) {
	for (int e = 0; e < pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
			return 1;
	return 0;
}

int num[MAX], min_num[MAX];
int k;
Stack S;
int on_stack[MAX];

int min(int a, int b) {
	return (a > b ? b : a);
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int cnt = 0;

void SCC(Graph* pG, int u) {
	num[u] = min_num[u] = k; k++;
	push_back(&S, u);
	on_stack[u] = 1;

	for (int v = 1; v <= pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (num[v] < 0) {
				SCC(pG, v);
				min_num[u] = min(min_num[u], min_num[v]);
			}
			else if (on_stack[v])
				min_num[u] = min(min_num[u], num[v]);
		}
	}

	if (num[u] == min_num[u]) {
		cnt++;
		int w;
		do {
			w = top(&S);
			pop_back(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (int u = 1; u <= G.n; u++) {
		num[u] = -1;
		on_stack[u] = 0;
	}

	k = 1;
	make_null_stack(&S);


	for (int u = 1; u <= G.n; u++)
		if (num[u] == -1) {
			SCC(&G, u);
		}
	
	printf("%d", cnt);
	return 0;
}
--------------------------------------------------------------------------------------------------


Moore – Dijkstra
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			pG->W[u][v] = NO_EDGE;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999

int mark[100];
int pi[100];
int p[100];

void MooreDijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		pi[u] = oo;
		mark[u] = 0;
	}

	pi[s] = 0;
	p[s] = -1;
	int u, v;
	for (int i = 1; i < pG->n; i++) {
		int min_pi = oo;
		for (int j = 1; j <= pG->n; j++) {
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}
		mark[u] = 1;

		for (v = 1; v <= pG->n; v++) {
			if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
		}
	}
}

int main() {
	int n, m;
	Graph G;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	MooreDijkstra(&G, 1);

	for (int u = 1; u <= G.n; u++)
		printf("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);

	return 0;
}
------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			pG->W[u][v] = NO_EDGE;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->W[v][u] = w;
	pG->m++;
}

#define oo 999999

int mark[100];
int pi[100];
int p[100];

void MooreDijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		pi[u] = oo;
		mark[u] = 0;
	}

	pi[s] = 0;
	p[s] = -1;
	int u, v;
	for (int i = 1; i < pG->n; i++) {
		int min_pi = oo;
		for (int j = 1; j <= pG->n; j++) {
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}
		mark[u] = 1;

		for (v = 1; v <= pG->n; v++) {
			if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
		}
	}
}

int main() {
	int n, m;
	Graph G;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	MooreDijkstra(&G, 1);

	for (int u = 1; u <= G.n; u++)
		printf("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);

	return 0;
}
-----------------------------------------------------------------------------------------------------------------
chieu dai duong di ngan nhat
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Dijkstra(&G, 1);
	if (pi[n] < oo)
		printf("%d", pi[n]);
	else
		printf("-1");
	return 0;
}
---------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->W[v][u] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Dijkstra(&G, 1);
	if (pi[n] < oo)
		printf("%d", pi[n]);
	else
		printf("-1");
	return 0;
}
------------------------------------------------------------------------------------------------------------------


duong di ngan nhat
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	//pG->W[v][u] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m, s, t;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	scanf("%d %d", &s, &t);
	Dijkstra(&G, s);
	int path[100];
	int cnt = 0;
	while (t != s) {
		path[cnt] = t;
		t = p[t];
		cnt++;
	}
	path[cnt] = s;
	for (int i = cnt; i > 0; i--)
		printf("%d -> ", path[i]);
	printf("%d", path[0]);
	return 0;
}
-------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->W[v][u] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m, s, t;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	scanf("%d %d", &s, &t);
	Dijkstra(&G, s);
	int path[100];
	int cnt = 0;
	while (t != s) {
		path[cnt] = t;
		t = p[t];
		cnt++;
	}
	path[cnt] = s;
	for (int i = cnt; i > 0; i--)
		printf("%d -> ", path[i]);
	printf("%d", path[0]);
	return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------



me cung so
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	Graph G;
	init_graph(&G, n * m);
	for (int i = 1; i <= n * m; i++) {
		int w;
		scanf("%d", &w);
		if (i > n) {
			add_edge(&G, i - n, i, w);
			if (i + n <= n * m)
				add_edge(&G, i + n, i, w);
		}
		if ((i - 1) % n != 0)
			add_edge(&G, i - 1, i, w);
		if (i % n != 0)
			add_edge(&G, i + 1, i, w);
	}
	Dijkstra(&G, 1);
	
	printf("%d", pi[n*m]);
	return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------


Nguu lang chuc nu o kieu
#include <stdio.h>

#define NO_EDGE -1

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->W[v][u] = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void Dijkstra(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;
	int u;
	for (int i = 1; i < pG->n; i++) {
		int minpi = oo;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pi[v] < minpi) {
				minpi = pi[v];
				u = v;
			}
		}
		mark[u] = 1;
		for (int v = 1; v <= pG->n; v++) {
			if (!mark[v] && pG->W[u][v] != NO_EDGE) {
				if (pi[u] + pG->W[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->W[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Dijkstra(&G, 1);
	
	printf("%d", pi[n]);
	return 0;
}
----------------------------------------------------------------------------------------------------------------------


bellman-ford
#include <stdio.h>

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void BellmanFord(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;

	for (int i = 1; i < pG->n; i++) {
		for (int e = 0; e < pG->m; e++) {
			int u = pG->edges[e].u;
			int v = pG->edges[e].v;
			int w = pG->edges[e].w;
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	BellmanFord(&G, 1);
	if (pi[n] < oo)
		printf("%d", pi[n]);
	else
		printf("-1");
	return 0;
}
----------------------------------------------------------------------------------------------------------
#include <stdio.h>

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void BellmanFord(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;

	for (int i = 1; i < pG->n; i++) {
		for (int e = 0; e < pG->m; e++) {
			int u = pG->edges[e].u;
			int v = pG->edges[e].v;
			int w = pG->edges[e].w;
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	BellmanFord(&G, s);
	int path[100];
	int cnt = 0;
	if (pi[t] < oo) {
		while (t != s) {
			path[cnt] = t;
			t = p[t];
			cnt++;
		}
		path[cnt] = s;
		for (int i = cnt; i > 0; i--)
			printf("%d -> ", path[i]);
		printf("%d", path[0]);
	}
	return 0;
}
------------------------------------------------------------------------------------------------------------



bellman-ford kiem tra chu trinh am
#include <stdio.h>

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

int BellmanFord(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;

	for (int i = 1; i < pG->n; i++) {
		for (int e = 0; e < pG->m; e++) {
			int u = pG->edges[e].u;
			int v = pG->edges[e].v;
			int w = pG->edges[e].w;

			if (pi[u] == oo)
				continue;

			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	for (int e = 0; e < pG->m; e++) {
		int u = pG->edges[e].u;
		int v = pG->edges[e].v;
		int w = pG->edges[e].w;
		if (pi[u] == oo)
				continue;
		if (pi[u] + w < pi[v]) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int s;
	scanf("%d", &s);
	if (BellmanFord(&G, s))
		printf("YES");
	else
		printf("NO");
	return 0;
}
-----------------------------------------------------------------------------------------------------------------


Thanh pho Dhaka
#include <stdio.h>

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 999999
int mark[100], p[100], pi[100];

void BellmanFord(Graph* pG, int s) {
	for (int u = 1; u <= pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1;

	for (int i = 1; i < pG->n; i++) {
		for (int e = 0; e < pG->m; e++) {
			int u = pG->edges[e].u;
			int v = pG->edges[e].v;
			int w = pG->edges[e].w;

			if (pi[u] == oo)
				continue;

			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

int b[100];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d", &u, &v);
		w = (b[v] - b[u]) * (b[v] - b[u]) * (b[v] - b[u]);
		add_edge(&G, u, v, w);
	}
	int s, t;
	scanf("%d %d", &s, &t);
	BellmanFord(&G, s);
	if (pi[t] < oo)
		printf("%d", pi[t]);
	else
		printf("?");
	return 0;
}
--------------------------------------------------------------------------------------------------------------------


 Floyd - Warshall
 #include <stdio.h>

#define NO_EDGE 0

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int pi[100][100];
int next[100][100];

void FloydWarshall(Graph* pG) {
	for (int u = 1; u <= pG->n; u++) {
		for (int v = 1; v <= pG->n; v++) {
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	for (int u = 1; u <= pG->n; u++)
		pi[u][u] = 0;
	for (int u = 1; u <= pG->n; u++)
		for (int v = 1; v <= pG->n; v++)
			if (pG->W[u][v] != NO_EDGE) {
				pi[u][v] = pG->W[u][v];
				next[u][v] = v;
			}

	for (int k = 1; k <= pG->n; k++)
		for (int u = 1; u <= pG->n; u++) {
			if (pi[u][k] == oo)
				continue;
			for (int v = 1; v <= pG->n; v++) {
				if (pi[k][v] == oo)
					continue;
				if (pi[u][k] + pi[k][v] < pi[u][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	FloydWarshall(&G);
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (pi[u][v] < oo)
				printf("%d -> %d: %d\n", u, v, pi[u][v]);
			else
				printf("%d -> %d: NO PATH\n", u, v);
		}
	}
	return 0;
}
----------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define NO_EDGE 0

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int pi[100][100];
int next[100][100];

void FloydWarshall(Graph* pG) {
	for (int u = 1; u <= pG->n; u++) {
		for (int v = 1; v <= pG->n; v++) {
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	for (int u = 1; u <= pG->n; u++)
		pi[u][u] = 0;
	for (int u = 1; u <= pG->n; u++)
		for (int v = 1; v <= pG->n; v++)
			if (pG->W[u][v] != NO_EDGE) {
				pi[u][v] = pG->W[u][v];
				next[u][v] = v;
			}

	for (int k = 1; k <= pG->n; k++)
		for (int u = 1; u <= pG->n; u++) {
			if (pi[u][k] == oo)
				continue;
			for (int v = 1; v <= pG->n; v++) {
				if (pi[k][v] == oo)
					continue;
				if (pi[u][k] + pi[k][v] < pi[u][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	FloydWarshall(&G);
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (pi[u][v] < oo)
			{
				printf("path(%d, %d): %d", u, v, u);
				int s = u, t = v;
				while (s != t) {
					s = next[s][t];
					printf(" -> %d", s);
				}
				printf("\n");
			}
			else
				printf("path(%d, %d): NO PATH\n", u, v);
		}
	}
	return 0;
}
--------------------------------------------------------------------------------------------------------


 Floyd - Warshall kiem tra chu trinh am
 #include <stdio.h>

#define NO_EDGE 0

typedef struct {
	int n, m;
	int W[100][100];
}Graph;

void init_graph(Graph* pG, int n) {
	pG->n = n;
	pG->m = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			pG->W[u][v] = NO_EDGE;
		}
	}
}

void add_edge(Graph* pG, int u, int v, int w) {
	pG->W[u][v] = w;
	pG->m++;
}

#define oo 999999
int pi[100][100];
int next[100][100];

int FloydWarshall(Graph* pG) {
	for (int u = 1; u <= pG->n; u++) {
		for (int v = 1; v <= pG->n; v++) {
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	for (int u = 1; u <= pG->n; u++)
		pi[u][u] = 0;
	for (int u = 1; u <= pG->n; u++)
		for (int v = 1; v <= pG->n; v++)
			if (pG->W[u][v] != NO_EDGE) {
				pi[u][v] = pG->W[u][v];
				next[u][v] = v;
			}

	for (int k = 1; k <= pG->n; k++)
		for (int u = 1; u <= pG->n; u++) {
			if (pi[u][k] == oo)
				continue;
			for (int v = 1; v <= pG->n; v++) {
				if (pi[k][v] == oo)
					continue;
				if (pi[u][k] + pi[k][v] < pi[u][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}


	for (int u = 1; u <= pG->n; u++)
		if (pi[u][u] < 0) {
			return 1;
		}
	return 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	if (FloydWarshall(&G))
		printf("YES");
	else
		printf("NO");
	
	return 0;
}
---------------------------------------------------------------------------------------------------------------------


sap xep topo chieu rong
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;


typedef struct
{
    ElementType data[MAX_N];
    int front, rear;
} Queue;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}
void enqueue(Queue *pQ, ElementType u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

void topo_sort(Graph *pG, List *pL){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    Queue Q;

    make_null_queue(&Q);

    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            enqueue(&Q, u);

    make_null_list(pL);
    
    while(!empty(&Q)){
        ElementType u = front(&Q);
        printf("%d ", u);
        push_back(pL, u);
        dequeue(&Q);
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[u][v] > 0){
                d[v]--;
                if(d[v] == 0)
                    enqueue(&Q, v);
            }
        }
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    List L;
    topo_sort(&G, &L);
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int mark[MAX_N];

void dfs(Graph G, int u, List *pL){
    mark[u] = 1;
    for(int v = 1; v <= G.n; v++){
        if(G.A[u][v] > 0){
            if(mark[v] == 0)
                dfs(G, v, pL);
        }
    }
    push_back(pL, u);
}

void topo_sort(Graph G, List *pL){
    for(int u = 1; u <= G.n; u++) mark[u] = 0;

    for(int u = 1; u <= G.n; u++){
        if(mark[u] == 0)
            dfs(G, u, pL);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    List L;
    topo_sort(G, &L);
    for(int i = L.size; i > 0; i--)
        printf("%d ", element_at(&L, i));

    return 0;
}
---------------------------------------------------------------------------------------------------------------------


xep da peter
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;


typedef struct
{
    ElementType data[MAX_N];
    int front, rear;
} Queue;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}
void enqueue(Queue *pQ, ElementType u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

void topo_sort(Graph *pG, List *pL){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    Queue Q;

    make_null_queue(&Q);

    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            enqueue(&Q, u);

    make_null_list(pL);
    
    while(!empty(&Q)){
        ElementType u = front(&Q);
        printf("%d\n", u);
        push_back(pL, u);
        dequeue(&Q);
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[u][v] > 0){
                d[v]--;
                if(d[v] == 0)
                    enqueue(&Q, v);
            }
        }
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    List L;
    topo_sort(&G, &L);
    return 0;
}
--------------------------------------------------------------------------------------------------------------------


xep hang cac dinh
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void copy_list(List *pS1, List *pS2){
    make_null_list(pS1);
    for(int i = 1; i <= pS2->size; i++)
        push_back(pS1, element_at(pS2, i));    
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int r[MAX_N];

void rank(Graph *pG){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    List S1, S2;
    make_null_list(&S1);
    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            push_back(&S1, u);
    
    int k = 0;
    while(S1.size > 0){
        make_null_list(&S2);
        for(int i = 1; i <= S1.size; i++){
            int u = element_at(&S1, i);
            r[u] = k;
            for(int v = 1; v <= pG->n; v++){
                if(pG->A[u][v] != 0){
                    d[v]--;
                    if(d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        k++;
        copy_list(&S1, &S2);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    rank(&G);

    for(int u = 1; u <= G.n; u++)
        printf("r[%d] = %d\n", u, r[u]);

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void copy_list(List *pS1, List *pS2){
    make_null_list(pS1);
    for(int i = 1; i <= pS2->size; i++)
        push_back(pS1, element_at(pS2, i));    
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int r[MAX_N];

void rank(Graph *pG){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    List S1, S2;
    make_null_list(&S1);
    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            push_back(&S1, u);
    
    int k = 0;
    while(S1.size > 0){
        make_null_list(&S2);
        for(int i = 1; i <= S1.size; i++){
            int u = element_at(&S1, i);
            r[u] = k;
            for(int v = 1; v <= pG->n; v++){
                if(pG->A[u][v] != 0){
                    d[v]--;
                    if(d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        k++;
        copy_list(&S1, &S2);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    rank(&G);

    for(int u = 1; u <= G.n; u++)
        printf("r[%d] = %d\n", u, r[u]);

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------


co giao Trang chia keo
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void copy_list(List *pS1, List *pS2){
    make_null_list(pS1);
    for(int i = 1; i <= pS2->size; i++)
        push_back(pS1, element_at(pS2, i));    
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int r[MAX_N];

void rank(Graph *pG){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    List S1, S2;
    make_null_list(&S1);
    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            push_back(&S1, u);
    
    int k = 0;
    while(S1.size > 0){
        make_null_list(&S2);
        for(int i = 1; i <= S1.size; i++){
            int u = element_at(&S1, i);
            r[u] = k;
            for(int v = 1; v <= pG->n; v++){
                if(pG->A[u][v] != 0){
                    d[v]--;
                    if(d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        k++;
        copy_list(&S1, &S2);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, v, u);
    }
    rank(&G);
    int sum = 0;
    for(int u = 1; u <= G.n; u++){
        printf("%d\n", r[u] + 1);
        sum += (r[u] + 1);
    }
    printf("%d", sum);
    return 0;
}
---------------------------------------------------------------------------------------------------------
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void copy_list(List *pS1, List *pS2){
    make_null_list(pS1);
    for(int i = 1; i <= pS2->size; i++)
        push_back(pS1, element_at(pS2, i));    
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

int r[MAX_N];

void rank(Graph *pG){
    int d[MAX_N];
    for(int u = 1; u <= pG->n; u++){
        d[u] = 0;
        for(int v = 1; v <= pG->n; v++){
            if(pG->A[v][u] > 0)
                d[u]++;
        }
    }

    List S1, S2;
    make_null_list(&S1);
    for(int u = 1; u <= pG->n; u++)
        if(d[u] == 0)
            push_back(&S1, u);
    
    int k = 1;
    while(S1.size > 0){
        make_null_list(&S2);
        for(int i = 1; i <= S1.size; i++){
            int u = element_at(&S1, i);
            r[u] = k;
            for(int v = 1; v <= pG->n; v++){
                if(pG->A[u][v] != 0){
                    d[v]--;
                    if(d[v] == 0)
                        push_back(&S2, v);
                }
            }
        }
        k++;
        copy_list(&S1, &S2);
    }
}

int main()
{
    int n, m;
    Graph G;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    rank(&G);

    for(int u = 1; u <= G.n; u++)
        printf("%d ", r[u]);

    return 0;
}
---------------------------------------------------------------------------------------------------------------------



quan ly du an
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

typedef struct
{
    ElementType data[MAX_N];
    int front, rear;
} Queue;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}
void enqueue(Queue *pQ, ElementType u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

void topo_sort(Graph *pG, List *pL)
{
    int d[MAX_N];
    for (int u = 1; u <= pG->n; u++)
    {
        d[u] = 0;
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->A[v][u] > 0)
                d[u]++;
        }
    }

    Queue Q;

    make_null_queue(&Q);

    for (int u = 1; u <= pG->n; u++)
        if (d[u] == 0)
            enqueue(&Q, u);

    make_null_list(pL);

    while (!empty(&Q))
    {
        ElementType u = front(&Q);
        // printf("%d\n", u);
        push_back(pL, u);
        dequeue(&Q);
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->A[u][v] > 0)
            {
                d[v]--;
                if (d[v] == 0)
                    enqueue(&Q, v);
            }
        }
    }
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int max(int a, int b)
{
    return (a < b) ? b : a;
}

int indeg(Graph G, int u)
{
    int indeg_u = 0;
    for (int v = 1; v <= G.n; v++)
        if (G.A[v][u] > 0)
            indeg_u++;
    return indeg_u;
}

int outdeg(Graph G, int u)
{
    int indeg_u = 0;
    for (int v = 1; v <= G.n; v++)
        if (G.A[u][v] > 0)
            indeg_u++;
    return indeg_u;
}

int d[MAX_N];
int main()
{
    int n;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n + 2);
    int alpha = n + 1, beta = n + 2;
    d[alpha] = 0;
    for (int u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
        int v;
        scanf("%d", &v);
        while (v != 0)
        {
            add_edge(&G, v, u);
            scanf("%d", &v);
        }
    }

    for (int u = 1; u <= n; u++)
    {
        if (indeg(G, u) == 0)
            add_edge(&G, alpha, u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (outdeg(G, u) == 0)
            add_edge(&G, u, beta);
    }
    List L;
    topo_sort(&G, &L);
    int t[MAX_N];
    t[alpha] = 0;

    for (int j = 2; j <= L.size; j++)
    {
        int u = element_at(&L, j);
        t[u] = -999999;
        for (int x = 1; x <= G.n; x++)
            if (G.A[x][u] > 0)
                t[u] = max(t[u], t[x] + d[x]);
    }
    int T[MAX_N];
    T[beta] = t[beta];
    for (int j = L.size - 1; j >= 1; j--)
    {
        int u = element_at(&L, j);
        T[u] = +999999;
        for (int v = 1; v <= G.n; v++)
            if (G.A[u][v] > 0)
                T[u] = min(T[u], T[v] - d[u]);
    }

    for (int u = 1; u <= n; u++)
        printf("%d %d\n", t[u], T[u]);
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------

quan ly du an phan mem
#include <stdio.h>

#define MAX_N 100
typedef int ElementType;

typedef struct
{
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct
{
    ElementType data[MAX_N];
    int size;
} List;

typedef struct
{
    ElementType data[MAX_N];
    int front, rear;
} Queue;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->data[pL->size] = x;
    pL->size++;
}

ElementType element_at(List *pL, int i)
{
    return pL->data[i - 1];
}

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}
void enqueue(Queue *pQ, ElementType u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->m++;
}

void topo_sort(Graph *pG, List *pL)
{
    int d[MAX_N];
    for (int u = 1; u <= pG->n; u++)
    {
        d[u] = 0;
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->A[v][u] > 0)
                d[u]++;
        }
    }

    Queue Q;

    make_null_queue(&Q);

    for (int u = 1; u <= pG->n; u++)
        if (d[u] == 0)
            enqueue(&Q, u);

    make_null_list(pL);

    while (!empty(&Q))
    {
        ElementType u = front(&Q);
        // printf("%d\n", u);
        push_back(pL, u);
        dequeue(&Q);
        for (int v = 1; v <= pG->n; v++)
        {
            if (pG->A[u][v] > 0)
            {
                d[v]--;
                if (d[v] == 0)
                    enqueue(&Q, v);
            }
        }
    }
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int max(int a, int b)
{
    return (a < b) ? b : a;
}

int indeg(Graph G, int u)
{
    int indeg_u = 0;
    for (int v = 1; v <= G.n; v++)
        if (G.A[v][u] > 0)
            indeg_u++;
    return indeg_u;
}

int outdeg(Graph G, int u)
{
    int indeg_u = 0;
    for (int v = 1; v <= G.n; v++)
        if (G.A[u][v] > 0)
            indeg_u++;
    return indeg_u;
}

int d[MAX_N];
int main()
{
    int n, m;
    Graph G;
    scanf("%d", &n);
    init_graph(&G, n + 2);
    int alpha = n + 1, beta = n + 2;
    d[alpha] = 0;
    for (int u = 1; u <= n; u++)
    {
        scanf("%d", &d[u]);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d",&u, &v);
        add_edge(&G, u, v);
    }

    for (int u = 1; u <= n; u++)
    {
        if (indeg(G, u) == 0)
            add_edge(&G, alpha, u);
    }

    for (int u = 1; u <= n; u++)
    {
        if (outdeg(G, u) == 0)
            add_edge(&G, u, beta);
    }
    List L;
    topo_sort(&G, &L);
    int t[MAX_N];
    t[alpha] = 0;

    for (int j = 2; j <= L.size; j++)
    {
        int u = element_at(&L, j);
        t[u] = -999999;
        for (int x = 1; x <= G.n; x++)
            if (G.A[x][u] > 0)
                t[u] = max(t[u], t[x] + d[x]);
    }
    int T[MAX_N];
    T[beta] = t[beta];
    for (int j = L.size - 1; j >= 1; j--)
    {
        int u = element_at(&L, j);
        T[u] = +999999;
        for (int v = 1; v <= G.n; v++)
            if (G.A[u][v] > 0)
                T[u] = min(T[u], T[v] - d[u]);
    }

    printf("%d", t[beta]);
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------








