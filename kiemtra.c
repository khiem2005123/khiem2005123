Ham init_graph
void init_graph(Graph *pG,int n){
    pG->n=n;
    pG->m=0;
}


Ham add_edge 8

void add_edge(Graph *pG, int x, int y) {
    pG->edges[pG->m].x=x;
    pG->edges[pG->m].y=y;
    pG->m++;
}


Ham add_edge nang cao 16
void add_edge(Graph *pG, int x, int y) {
    if (x < 1 || x > pG->n || y < 1 || y > pG->n) {
        return; 
    }
    if (pG->m < MAX_EDGES) {
        pG->edges[pG->m].x = x;
        pG->edges[pG->m].y = y;
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


Ham adjacent 59
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
----------------------------------------------------- 80
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
--------------------------------------------------------------------------------------------------- 113
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
------------------------------------------------------------------------------------------ 158
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


Liet ke dinh ke 213
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
----------------------------------------------------------------------------------------------- 269
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




Ma tran ke 329
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




Ham add_edge ma tran ke 395
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



in ma tran ke 434
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
----------------------------------------------------------------------------------------------- 479
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
---------------------------------------------------------------------------------- 523
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
--------------------------------------------------------------------------------- 569
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




Ham tinh bac ma tran ke 618
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
----------------------------------------------------------------------------- 668
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
----------------------------------------------------------------------------------- 716
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
---------------------------------------------------------------------------------------- 764
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



Liet ke dinh ke ma tran ke 816
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
-------------------------------------------------------------------------- 868
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



chuyen doi giua cac pp bieu dien 922
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
------------------------------------------------------------------------------------------------- 946
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
------------------------------------------------------------------------------------------------- 970
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
------------------------------------------------------------------------------------------------- 996
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
------------------------------------------------------------------------------------------------- 1022
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
------------------------------------------------------------------------------------------- 1059
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




bfs tu 1 dinh 1100
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
---------------------------------------------------------------------------------------- 1194
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
------------------------------------------------------------------------------------------------ 1287
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
--------------------------------------------------------------------------------------------- 1382
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


bfs toan bo do thi 1479
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
--------------------------------------------------------------------------------------------- 1578
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



dfs tu 1 dinh 1680

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
------------------------------------------------------------------------------------- 1779

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
------------------------------------------------------------------------------------ 1877
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
----------------------------------------------------------------------------------------- 1975
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


dfs toan bo do thi 2075
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
------------------------------------------------------------------------------------------------------- 2173
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



cay duyet do thi 2274
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
----------------------------------------------------------------------------------------------- 2386
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
------------------------------------------------------------------------------------------------- 2497
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
--------------------------------------------------------------------------------------------------------- 2610
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


kiem tra lien thong 2725
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
---------------------------------------------------------------------------------------------- 2798


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
------------------------------------------------------------------------------------------------------- 2870
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
------------------------------------------------------------------------------------------- 2938
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
---------------------------------------------------------------------------------------------- 3008
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


hon dao 3080
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
ton ngo khong 3149
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


kiem tra chu trinh 3220
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
----------------------------------------------------------------------------------------------------- 3299
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
---------------------------------------------------------------------------------------------------------- 3400
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
--------------------------------------------------------------------------------------------------- 3481
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
excel 3587
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
haddock 3673
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


do thi phan doi 3761
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
----------------------------------------------------------------------------------------------------- 3841
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


Tarjan 3932
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
lien thong manh 4056

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
-------------------------------------------------------------------------------------------------------------- 4187
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
---------------------------------------------------------------------------------------------- 4316
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


come and go 4454
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
Trust group 4592



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


Moore – Dijkstra 4729
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
------------------------------------------------------------------------------------------------------------------------------4805
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
chieu dai duong di ngan nhat 4883
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
---------------------------------------------------------------------------------------------------------4956
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


duong di ngan nhat 5033
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
-------------------------------------------------------------------------------------------------------------5115
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



me cung so 5201
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


Nguu lang chuc nu o kieu 5283
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


bellman-ford 5358
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
----------------------------------------------------------------------------------------------------------5423
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



bellman-ford kiem tra chu trinh am 5503
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


Thanh pho Dhaka 5587
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


 Floyd - Warshall 5666
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
----------------------------------------------------------------------------------------------------------------------5747
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


 Floyd - Warshall kiem tra chu trinh am 5839
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


sap xep topo chieu rong 5926
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
----------------------------------------------------------------------------------------------------------------------------------- 6059
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


xep da peter 6152
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


xep hang cac dinh 6288
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
----------------------------------------------------------------------------------------------------------------------- 6399
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


co giao Trang chia keo 6513
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
--------------------------------------------------------------------------------------------------------- 6626
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



quan ly du an 6741
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

quan ly du an phan mem 6953
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

Tim cay khung co trong so nho nhat bang Kruskal 7164
#include <stdio.h>

typedef struct {
	int u, v;
	int w;
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
	if (u != v) {
		pG->edges[pG->m].v = u;
		pG->edges[pG->m].u = v;
		pG->edges[pG->m].w = w;
	}
	pG->m++;
}

void Swap(Edge* a, Edge* b) {
	Edge tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(Graph* pG) {
	for (int i = 0; i < pG->m - 1; i++) {
		for (int j = pG->m - 1; j > i; j--) {
			if (pG->edges[j].w < pG->edges[j - 1].w)
				Swap(&pG->edges[j], &pG->edges[j - 1]);
		}
	}
}

int findroot(int parent[], int u) {
	if (u == parent[u]) {
		return u;
	}
	else{
		return findroot(parent, parent[u]);
	}
}

int parent[100];

int Kruskal(Graph* pG, Graph* pT) {
	BubbleSort(pG);
	for (int u = 1; u <= pG->n; u++)
		parent[u] = u;
	int sum = 0;
	init_graph(pT, pG->n);
	for (int e = 0; e < pG->m; e++) {
		int u = pG->edges[e].u;
		int v = pG->edges[e].v;
		int w = pG->edges[e].w;
		int root_u = findroot(parent, u);
		int root_v = findroot(parent, v);
		if (root_u != root_v) {
			add_edge(pT, u, v, w);
			sum += w;
			parent[root_v] = root_u;
		}
	}
	return sum;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G, T;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	printf("%d\n", Kruskal(&G, &T));
	for (int e = 0; e < T.m; e++) {
		if(T.edges[e].u <= T.edges[e].v)
		printf("%d %d %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
		else
			printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
	}
	return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------


Tim cay khung co trong so nho nhat bang Prim 7264
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

int Prim(Graph* pG, int s, Graph* pT) {
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
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m;
	Graph G, T;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	printf("%d\n", Prim(&G, 1, &T));
	for (int u = 1; u <= T.n; u++) {
		for (int v = u + 1; v <= T.n; v++) {
			if (T.W[u][v] != NO_EDGE)
				printf("%d %d %d\n", u, v, T.W[u][v]);
		}
	}
	return 0;
}

------------------------------------------------------------------------------------------------------------------------------

Xoa mot so cung cua G sao cho G van lien thong 7357
#include <stdio.h>

typedef struct {
	int u, v;
	int w;
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
	if (u != v) {
		pG->edges[pG->m].v = u;
		pG->edges[pG->m].u = v;
		pG->edges[pG->m].w = w;
	}
	pG->m++;
}

void Swap(Edge* a, Edge* b) {
	Edge tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(Graph* pG) {
	for (int i = 0; i < pG->m - 1; i++) {
		for (int j = pG->m - 1; j > i; j--) {
			if (pG->edges[j].w < pG->edges[j - 1].w)
				Swap(&pG->edges[j], &pG->edges[j - 1]);
		}
	}
}

int findroot(int parent[], int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return findroot(parent, parent[u]);
	}
}

int parent[100];

int Kruskal(Graph* pG, Graph* pT) {
	BubbleSort(pG);
	for (int u = 1; u <= pG->n; u++)
		parent[u] = u;
	int sum = 0;
	init_graph(pT, pG->n);
	for (int e = 0; e < pG->m; e++) {
		int u = pG->edges[e].u;
		int v = pG->edges[e].v;
		int w = pG->edges[e].w;
		int root_u = findroot(parent, u);
		int root_v = findroot(parent, v);
		if (root_u != root_v) {
			add_edge(pT, u, v, w);
			sum += w;
			parent[root_v] = root_u;
		}
	}
	return sum;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Graph G, T;
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w_G = 0;
	for (int e = 0; e < G.m; e++)
		sum_w_G += G.edges[e].w;
	printf("%d", sum_w_G - Kruskal(&G, &T));
	return 0;
}


--------------------------------------------------------------------------------------------------------------------

Tim cay khung co trong so nho nhat bang prim 7454
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

int Prim(Graph* pG, int s, Graph* pT) {
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
		printf("%d\n", u);
		for (v = 1; v <= pG->n; v++) {
			if (pG->W[u][v] != NO_EDGE && mark[v] == 0)
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m;
	Graph G, T;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	Prim(&G, 1, &T);
	for (int u = 1; u <= n; u++) {
		if (!mark[u])
			printf("%d\n", u);
	}
	return 0;
}


------------------------------------------------------------------------------------------------------------------------------

Nguu lang chuc nu 7546
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

int Prim(Graph* pG, int s, Graph* pT) {
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
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m, k;
	Graph G, T;
	scanf("%d %d %d", &n, &m, &k);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	int sum_w = Prim(&G, 1, &T);
	if (sum_w <= k)
		printf("OK");
	else
		printf("%d", sum_w - k);

	return 0;
}

-------------------------------------------------------------------------------------------------------------------------


Ly Thuong Kiet 7638
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

int Prim(Graph* pG, int s, Graph* pT) {
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
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m;
	Graph G, T;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	printf("%d", Prim(&G, 1, &T));

	return 0;
}


-----------------------------------------------------------------------------------------------------------------------------

Hoang tho dien 7726
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

int Prim(Graph* pG, int s, Graph* pT) {
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
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m;
	Graph G, T;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, s, d;
		scanf("%d %d %d %d", &u, &v, &s, & d);
		add_edge(&G, u, v, s*d);
	}

	printf("%d", Prim(&G, 1, &T));

	return 0;
}
------------------------------------------------------------------------------------------------------------------


Bay Nai va n bai co 7813
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

int Prim(Graph* pG, int s, Graph* pT) {
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
				if (pG->W[u][v] < pi[v]) {
					pi[v] = pG->W[u][v];
					p[v] = u;
				}
		}
	}

	init_graph(pT, pG->n);
	int sum = 0;
	for (u = 1; u <= pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum += w;
		}
	}
	return sum;
}

int main() {
	int n, m;
	Graph G, T;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}

	printf("%d", Prim(&G, 1, &T));

	return 0;
}
-------------------------------------------------------------------------------------------------------------------------

Tim luong cuc dai tren mang ford=furkerson 7899
#include <stdio.h>

#include <stdio.h>
#define MAX_N 100
#define INF 99999

typedef struct {
    int C[MAX_N][MAX_N];
    int F[MAX_N][MAX_N];
    int n;
}Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
}

typedef struct {
    int dir;
    int p;
    int sigma;
}Label;

Label label[MAX_N];

typedef struct {
    int Q[MAX_N];
    int front, rear;
}Queue;

void makenullQueue(Queue* pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

int empty(Queue Q) {
    return Q.front > Q.rear;
}

void enQueue(Queue* pQ, int x) {
    pQ->rear++;
    pQ->Q[pQ->rear] = x;
}

int pop(Queue* pQ) {
    int x = pQ->Q[pQ->front++];
    return x;
}

void init_flow(Graph* pG) {
    int i, j;
    for (i = 1; i <= pG->n; i++)
        for (j = 1; j <= pG->n; j++)
            pG->F[i][j] = 0;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int FordFulkerson(Graph* pG, int s, int t) {
    int i, j;
    init_flow(pG);
    int max_flow = 0;
    Queue Q;
    do {
        for (i = 1; i <= pG->n; i++)
            label[i].dir = 0;
        label[s].dir = +1;
        label[s].p = s;
        label[s].sigma = INF;

        makenullQueue(&Q);
        enQueue(&Q, s);
        int found = 0;
        while (!empty(Q)) {
            int u = pop(&Q);
            for (j = 1; j <= pG->n; j++) {
                if (pG->C[u][j] != 0 && !label[j].dir && pG->F[u][j] < pG->C[u][j]) {
                    label[j].dir = +1;
                    label[j].p = u;
                    label[j].sigma = min(label[u].sigma, pG->C[u][j] - pG->F[u][j]);
                    enQueue(&Q, j);
                }
            }
            for (j = 1; j <= pG->n; j++) {
                if (pG->C[j][u] != 0 && !label[j].dir && pG->F[j][u] > 0) {
                    label[j].dir = -1;
                    label[j].p = u;
                    label[j].sigma = min(label[u].sigma, pG->F[j][u]);
                    enQueue(&Q, j);
                }
            }
            if (label[t].dir != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            int sigma = label[t].sigma;
            int u = t;
            while (u != s) {
                int p = label[u].p;
                if (label[u].dir > 0)
                    pG->F[p][u] += sigma;
                else
                    pG->F[u][p] -= sigma;
                u = p;
            }
            max_flow += sigma;
        }
        else break;
    } while (1);
    return max_flow;
}


int main() {
    Graph G;
    int n, m, u, v, e, c, i;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &c);
        G.C[u][v] = c;
    }
    int max_flow = FordFulkerson(&G, 1, n);
    printf("Max flow: %d\n", max_flow);
    printf("S: ");
    for (i = 1; i <= n; i++) {
        if (label[i].dir)
            printf("%d ", i);
    }
    printf("\nT: ");
    for (i = 1; i <= n; i++) {
        if (!label[i].dir)
            printf("%d ", i);
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------

Kiem tra luong hop le 8042
#include <stdio.h>
#define MAX_N 100
#define INF 99999

typedef struct {
    int C[MAX_N][MAX_N];
    int F[MAX_N][MAX_N];
    int n;
}Graph;

void init_graph(Graph* pG, int n) {
    pG->n = n;
}

void add_edge(Graph* pG, int u, int v, int c, int f) {
    pG->C[u][v] = c;
    pG->F[u][v] = f;
}


int sum_incoming_flow(Graph* pG, int u) {
    int res = 0;
    int i;
    for (i = 1; i <= pG->n; i++)
        if (pG->C[i][u] != 0)
            res += pG->F[i][u];
    return res;
}

int sum_outgoing_flow(Graph* pG, int u) {
    int res = 0;
    int i;
    for (i = 1; i <= pG->n; i++)
        if (pG->C[u][i] != 0)
            res += pG->F[u][i];
    return res;
}

int check_flow(Graph* pG, int s, int t) {
    int k;
    if (sum_outgoing_flow(pG, s) != sum_incoming_flow(pG, t)) return 0;
    for (k = 1; k <= pG->n; k++) {
        if (k != s && k != t) {
            if (sum_outgoing_flow(pG, k) != sum_incoming_flow(pG, k)) return 0;
        }
    }
    return 1;
}

int main() {
    Graph G;
    int n, m, u, v, e, c, f;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d%d", &u, &v, &c, &f);
        if (c < f) {
            printf("NO");
            return 0;
        }
        add_edge(&G, u, v, c, f);
    }
    if (check_flow(&G, 1, n))
        printf("YES");
    else
    {
        printf("NO");
    }
    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------

In MTK nhap bang file
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
    FILE *file;
    
    file = fopen("dt1.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file dt1.txt\n");
        return 1;
    }
    
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    
    for (int e = 0; e < m; e++) {
        int u, v;
        fscanf(file, "%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    fclose(file);
    
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");
    }
    
    return 0;
}
------------------------------------------------------------------------------------------------------------


Add edge ma tran dinh cung 8173
void add_edge(Graph* G, int e, int x, int y) {
  
    if (x == y) {
      
        G->A[x][e] = 2;
    }
    else {
       
        G->A[x][e] = 1;
        G->A[y][e] = 1;
    }
}
------------------------------------------------------------------------------------------------------------

Add edge mt dinh cung k co khuyen 8188
void add_edge(Graph* G, int e, int x, int y) {

    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

Ham tinh bac ma tran dinh cung 8195
int deg(Graph* G, int x) {
    int degree = 0;
    for (int e = 1; e <= G->m; e++) {
        if (G->A[x][e] == 1) {
            degree++;
        }
    }
    return degree;
}
------------------------------------------------------------------------------------------------------------------

Ham tinh bac ma tran dinh cung 8207
int deg(Graph* G, int x) {
    int degree = 0;
    for (int e = 1; e <= G->m; e++) {
        if (G->A[x][e] == 1) {
            degree++;
        }
    }
    return degree;
}
--------------------------------------------------------------------------------------------------------
Ham List Neighbors ma tran dinh cung 8218
List neighbors(Graph* G, int x) {
    List L;
    make_null(&L);
    

    int added[100] = {0};
    

    for (int e = 1; e <= G->m; e++) {
  
        if (G->A[x][e] == 1) {
      
            for (int y = 1; y <= G->n; y++) {
            
                if (y != x && G->A[y][e] == 1 && !added[y]) {
                    push_back(&L, y);
                    added[y] = 1;  
                }
            }
        }
    }
    

    for (int i = 0; i < L.size - 1; i++) {
        for (int j = i + 1; j < L.size; j++) {
            if (L.data[i] > L.data[j]) {
                int temp = L.data[i];
                L.data[i] = L.data[j];
                L.data[j] = temp;
            }
        }
    }
    
    return L;
}
-------------------------------------------------------------------------------------------------------

Ham tinh bac ma tran dinh dinh 8256
int deg(Graph* G, int x) {
    int degree = 0;
    for (int y = 1; y <= G->n; y++) {
        if (G->A[x][y] > 0) {
            degree += G->A[x][y];
        }
    }
    return degree;
}
---------------------------------------------------------------------------------------------------------

Ham tinh bac ma tran dinh dinh bac chan 8268
int deg2(Graph* G) {
    int count = 0;
    
    for (int x = 1; x <= G->n; x++) {
        int degree = 0;
        
        for (int y = 1; y <= G->n; y++) {
            if (G->A[x][y] == 1) {
                degree++;
            }
        }
        
        if (degree % 2 == 0) {
            count++;
        }
    }
    
    return count;
}
----------------------------------------------------------------------------------------------------------

Ham dem so cung MT dinh dinh 8290
int edgeCount(Graph* G) {
    int count = 0;
    
    for (int i = 1; i <= G->n; i++) {
        for (int j = i + 1; j <= G->n; j++) {
            count += G->A[i][j];
        }
    }
    
    return count;
}
-------------------------------------------------------------------------------------------------------------

Tim dinh co bac lon nhat vo huong 8304
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

int degree(Graph *pG, int x) {
    int deg = 0;
    for(int v = 1; v <= pG->n; v++) {
        if(pG->A[x][v] == 1) {
            deg++;
        }
    }
    return deg;
}

int main() {
    
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    int max_deg = -1;
    int max_vertex = -1;
    
    for(int v = 1; v <= n; v++) {
        int deg = degree(&G, v);
        if(deg > max_deg) {
            max_deg = deg;
            max_vertex = v;
        }
    }
    
    printf("%d %d\n", max_vertex, max_deg);
    
    return 0;
}

------------------------------------------------------------------------------------------------------------------------------

BFS 8370
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct {
    int data[MAX_N];
    int front, rear;
} Queue;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

void make_null_queue(Queue *pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

void enqueue(Queue *pQ, int x) {
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

int dequeue(Queue *pQ) {
    int x = pQ->data[pQ->front];
    pQ->front++;
    return x;
}

int empty_queue(Queue *pQ) {
    return pQ->front > pQ->rear;
}

void bfs(Graph *pG, int start, int mark[]) {
    Queue Q;
    make_null_queue(&Q);
    
    enqueue(&Q, start);
    mark[start] = 1;
    printf("%d\n", start);
    
    while(!empty_queue(&Q)) {
        int u = dequeue(&Q);
        
        for(int v = 1; v <= pG->n; v++) {
            if(pG->A[u][v] == 1 && mark[v] == 0) {
                mark[v] = 1;
                enqueue(&Q, v);
                printf("%d\n", v);
            }
        }
    }
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    int mark[MAX_N];
    for(int i = 1; i <= n; i++) {
        mark[i] = 0;
    }
    
    bfs(&G, 1, mark);
    
    for(int i = 1; i <= n; i++) {
        if(mark[i] == 0) {
            bfs(&G, i, mark);
        }
    }
    
    return 0;
}
--------------------------------------------------------------------------------------------------------------------

DFS tu 1 dinh 8470
#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100

int n,m;


typedef int Vertices;
typedef struct{
    int matrix[maxv][maxv];
    Vertices n;
}Graph;


typedef struct{
    int data[idx];
    int size;
}List;


typedef struct{
    int data[idx];
    int size;
}Stack;


void makenullStack(Stack *s){
    s->size=0;
}

bool emptyStack(Stack *s){
    return s->size==0;
}

void pushStack(Stack *s, int element){
    s->data[s->size]=element;
    s->size++;
}

int getStack(Stack *s){
    return s->data[s->size-1];
}

void delSize(Stack *s){
    s->size--;
}


void makenullList(List *l){
    l->size=0;
}

bool emptyList(List *l){
    return l->size==0;
}

void pushList(List *l, int element){
    l->data[l->size]=element;
    l->size++;
}

int getList(List *l, int index){
    return l->data[index-1];
}


void initGraph(Graph *g){
    g->n=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g->matrix[i][j]=0;
}

void addEdge(Graph *g, int x, int y){
    g->matrix[x][y]=1;
    g->matrix[y][x]=1;
}

bool adjacent(Graph *g, int x, int y){
    return g->matrix[x][y]==1;
}

List neighbors(Graph *g, int x){
    List L;
    makenullList(&L);
    for(int i=1;i<=n;i++){
        if(adjacent(g,x,i)){
            pushList(&L,i);
        }
    }
    return L;
}
int mark[maxv];


List DFS_Stack(Graph *g, int x){
    List rs;
    makenullList(&rs);
    Stack s;
    makenullStack(&s);
    pushStack(&s,x);
    while(!emptyStack(&s)){ 
        int u = getStack(&s);
        delSize(&s);
        if(mark[u]==1) continue; 
        pushList(&rs,u); 
        mark[u]=1; 
        List L = neighbors(g,u); 
        for(int j=1;j<=L.size;j++){
            int v = getList(&L,j); 
            if(mark[v]==0){ 
                pushStack(&s,v); 
            }
        }
    }
    return rs;
}
int main(){
    Graph g;
    scanf("%d%d",&n,&m);
    initGraph(&g);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        addEdge(&g,u,v);
    }
    
    for(int i=1;i<=n;i++) mark[i]=0;
    
    for(int i=1;i<=n;i++){
        if(mark[i]==0){ 
            List L = DFS_Stack(&g,i); 
            for(int j=1;j<=L.size;j++){
                int v = getList(&L,j);
                printf("%d\n",v); 
                mark[v]=1;
            }
        }
    }
    return 0;
}

DFS de quy 8614
#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100

int n,m; 


typedef int Vertices;
typedef struct{
    int matrix[maxv][maxv];
    Vertices n;
}Graph;


typedef struct{
    int data[idx];
    int size;
}List;




void makenullList(List *l){
    l->size=0;
}


bool emptyList(List *l){
    return l->size==0;
}


void pushList(List *l, int element){
    l->data[l->size]=element;
    l->size++;
}


int getList(List *l, int index){
    return l->data[index-1];
}




void initGraph(Graph *g){
    g->n=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g->matrix[i][j]=0;
}


void addEdge(Graph *g, int x, int y){
    g->matrix[x][y]=1;
    g->matrix[y][x]=1;
}


bool adjacent(Graph *g, int x, int y){
    return g->matrix[x][y]==1;
}


List neighbors(Graph *g, int x){
    List L;
    makenullList(&L);
    for(int i=1;i<=n;i++){
        if(adjacent(g,x,i)){
            pushList(&L,i);
        }
    }
    return L;
}
int mark[maxv];

void DFS_Recursion(Graph *g, int x){
    if(mark[x]==1) return; 
    mark[x]=1; 
    printf("%d\n",x); 
    List L = neighbors(g,x); 
    for(int j=1;j<=L.size;j++){
        int v = getList(&L,j); 
        DFS_Recursion(g,v); 
    }
}
int main(){
    Graph g;
    scanf("%d%d",&n,&m);
    initGraph(&g);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        addEdge(&g,u,v);
    }
    
    for(int i=1;i<=n;i++)
        mark[i]=0; 
    
    for(int i=1;i<=n;i++)
         DFS_Recursion(&g,i); 
	
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------

BFS cha 8722
#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100

int n,m;

typedef int Vertices;
typedef struct{
    int matrix[maxv][maxv];
    Vertices n;
}Graph;

typedef struct{
    int data[idx];
    int size;
}List;

typedef struct{
    int front;
    int rear;
    int data[maxv];
}Queue;


void makenullQueue(Queue *q){
    q->front=0;
    q->rear=-1;
}

bool emptyQueue(Queue *q){
    return q->front > q->rear;
}

void pushQueue(Queue *q, int element){
    q->rear++;
    q->data[q->rear]=element;
}

int getQueue(Queue *q){
    return q->data[q->front];
}

void plusFront(Queue *q){
    q->front++;
}

void makenullList(List *l){
    l->size=0;
}

bool emptyList(List *l){
    return l->size==0;
}

void pushList(List *l, int element){
    l->data[l->size]=element;
    l->size++;
}

int getList(List *l, int index){
    return l->data[index-1];
}


void initGraph(Graph *g){
    g->n=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g->matrix[i][j]=0;
        }
    }
}

void addEdge(Graph *g, int x, int y){
    g->matrix[x][y]=1;
    g->matrix[y][x]=1;
}

bool adjacent(Graph *g, int x, int y){
    return g->matrix[x][y]==1;
}

List neighbors(Graph *g, int x){
    List L;
    makenullList(&L);
    for(int i=1;i<=n;i++){
        if(adjacent(g,x,i)){
            pushList(&L,i);
        }
    }
    return L;
}

int mark[maxv];
int parent[maxv]; 


List BFS(Graph *g, int x){
    List rs; 
    makenullList(&rs);
    Queue q; 
    makenullQueue(&q);
    pushQueue(&q,x);
    parent[x]=0; 
    while(!emptyQueue(&q)){ 
        int u = getQueue(&q);
        plusFront(&q);
        if(mark[u]==1) continue; 
        pushList(&rs,u); 
        mark[u]=1;  
        List L = neighbors(g,u); 
        for(int j=1;j<=L.size;j++){
            int v = getList(&L,j); 
            if(mark[v]==0){ 
                pushQueue(&q,v); 
                if(parent[v]==-1){ 
                    parent[v]=u; 
                }
            }
        }
    }
    return rs;
}
int main(){ 
    Graph g;
    scanf("%d%d",&n,&m);
    initGraph(&g);
    int u,v;
    for(int e=1;e<=m;e++){
        scanf("%d%d",&u,&v);
        addEdge(&g,u,v);
    }

    for(int i=1;i<=n;i++){
        mark[i]=0;
        parent[i]=-1;
    } 
    
    for(int i=1;i<=n;i++){
        if(mark[i]==0){ 
            List L = BFS(&g,i);  
            for(int j=1;j<=L.size;j++){
                int v = getList(&L,j);
                
                mark[v]=1;
            }
        }
    }

    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,parent[i]); 
    return 0;
}
-----------------------------------------------------------------------------------------------------------


DFS cha 8880

#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100

int n,m;

typedef int Vertices;
typedef struct{
    int matrix[maxv][maxv];
    Vertices n;
}Graph;

typedef struct{
    int data[idx];
    int size;
}List;

typedef struct{
    int data[idx];
    int size;
}Stack;


void makenullStack(Stack *s){
    s->size=0;
}

bool emptyStack(Stack *s){
    return s->size==0;
}

void pushStack(Stack *s, int element){
    s->data[s->size]=element;
    s->size++;
}

int getStack(Stack *s){
    return s->data[s->size-1];
}

void delSize(Stack *s){
    s->size--;
}


void makenullList(List *l){
    l->size=0;
}

bool emptyList(List *l){
    return l->size==0;
}

void pushList(List *l, int element){
    l->data[l->size]=element;
    l->size++;
}

int getList(List *l, int index){
    return l->data[index-1];
}


void initGraph(Graph *g){
    g->n=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g->matrix[i][j]=0;
}

void addEdge(Graph *g, int x, int y){
    g->matrix[x][y]=1;
    g->matrix[y][x]=1;
}

bool adjacent(Graph *g, int x, int y){
    return g->matrix[x][y]==1;
}

List neighbors(Graph *g, int x){
    List L;
    makenullList(&L);
    for(int i=1;i<=n;i++){
        if(adjacent(g,x,i)){
            pushList(&L,i);
        }
    }
    return L;
}
int mark[maxv];
int parent[maxv]; 

List DFS_Stack(Graph *g, int x){
    List rs;
    makenullList(&rs);
    Stack s;
    makenullStack(&s);
    pushStack(&s,x);
    parent[x]=0; 
    while(!emptyStack(&s)){ 
        int u = getStack(&s);
        delSize(&s);
        if(mark[u]==1) continue; 
        pushList(&rs,u); 
        mark[u]=1; 
        List L = neighbors(g,u); 
        for(int j=1;j<=L.size;j++){
            int v = getList(&L,j); 
            if(mark[v]==0){ 
                pushStack(&s,v); 
                parent[v]=u; 
            }
        }
    }
    return rs;
}
int main(){
    Graph g;
    scanf("%d%d",&n,&m);
    initGraph(&g);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        addEdge(&g,u,v);
    }
    for(int i=1;i<=n;i++){
        mark[i]=0;
        parent[i]=-1;
    }
    
    for(int i=1;i<=n;i++){
        if(mark[i]==0){ 
            List L = DFS_Stack(&g,i); 
            for(int j=1;j<=L.size;j++){
                int v = getList(&L,j);
                mark[v]=1; 
            }
        }
    }

    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,parent[i]); 
    return 0;
}

---------------------------------------------------------------------------------------------------------------

DFS de quy cha 9030
#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100

int n,m; 


typedef int Vertices;
typedef struct{
    int matrix[maxv][maxv];
    Vertices n;
}Graph;

typedef struct{
    int data[idx];
    int size;
}List;


void makenullList(List *l){
    l->size=0;
}

bool emptyList(List *l){
    return l->size==0;
}

void pushList(List *l, int element){
    l->data[l->size]=element;
    l->size++;
}

int getList(List *l, int index){
    return l->data[index-1];
}


void initGraph(Graph *g){
    g->n=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g->matrix[i][j]=0;
}

void addEdge(Graph *g, int x, int y){
    g->matrix[x][y]=1;
    g->matrix[y][x]=1;
}

bool adjacent(Graph *g, int x, int y){
    return g->matrix[x][y]==1;
}

List neighbors(Graph *g, int x){
    List L;
    makenullList(&L);
    for(int i=1;i<=n;i++){
        if(adjacent(g,x,i)){
            pushList(&L,i);
        }
    }
    return L;
}

int mark[maxv];
int parent[maxv];

void DFS_Recursion(Graph *g, int x, int p){
    if(mark[x]==1) return; 
    mark[x]=1; 
    
    parent[x]=p; 
    List L = neighbors(g,x); 
    for(int j=1;j<=L.size;j++){
        int v = getList(&L,j); 
        DFS_Recursion(g,v,x); 
    }
}
int main(){
    Graph g;
    scanf("%d%d",&n,&m);
    initGraph(&g);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        addEdge(&g,u,v);
    }
    
    for(int i=1;i<=n;i++){
        mark[i]=0; 
        parent[i]=-1; 
    }
        
    for(int i=1;i<=n;i++)
         DFS_Recursion(&g,i,0); 
    
    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,parent[i]); 
    return 0;
}
----------------------------------------------------------------------------------------------------------
Kiem tra chu trinh k khuyen k da cung 9133
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

int color[MAX_N];
int has_cycle;

void dfs(Graph *pG, int u, int parent) {
    color[u] = 1;
    
    for(int v = 1; v <= pG->n; v++) {
        if(pG->A[u][v] == 1) {
            if(color[v] == 0) {
                dfs(pG, v, u);
            }
            else if(v != parent) {
                has_cycle = 1;
            }
        }
    }
    
    color[u] = 2;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for(int i = 1; i <= n; i++) {
        color[i] = 0;
    }
    has_cycle = 0;
    
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            dfs(&G, i, -1);
        }
    }
    
    if(has_cycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------
Kiem tra chu trinh co khuyen va da cung 9210
#include <stdio.h>

#define MAX_N 100
#define MAX_M 500

typedef struct {
    int u, v;
    int used;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].used = 0;
    pG->m++;
}

int color[MAX_N];
int has_cycle;

void dfs(Graph *pG, int u, int parent_edge) {
    color[u] = 1;
    
    for(int e = 0; e < pG->m; e++) {
        if(e == parent_edge) continue;
        
        int v = -1;
        if(pG->edges[e].u == u) {
            v = pG->edges[e].v;
        } else if(pG->edges[e].v == u) {
            v = pG->edges[e].u;
        }
        
        if(v != -1) {
            if(color[v] == 0) {
                dfs(pG, v, e);
            }
            else if(color[v] == 1) {
                has_cycle = 1;
            }
        }
    }
    
    color[u] = 2;
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for(int i = 1; i <= n; i++) {
        color[i] = 0;
    }
    has_cycle = 0;
    
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            dfs(&G, i, -1);
        }
    }
    
    if(has_cycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
------------------------------------------------------------------------------------------------------
David va doi bong 9300
#include <stdio.h>

#define MAX_N 100

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct {
    int data[MAX_N];
    int front, rear;
} Queue;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}

void make_null_queue(Queue *pQ) {
    pQ->front = 0;
    pQ->rear = -1;
}

void enqueue(Queue *pQ, int x) {
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

int dequeue(Queue *pQ) {
    int x = pQ->data[pQ->front];
    pQ->front++;
    return x;
}

int empty_queue(Queue *pQ) {
    return pQ->front > pQ->rear;
}

int color[MAX_N];
int is_bipartite;

void bfs_bipartite(Graph *pG, int start) {
    Queue Q;
    make_null_queue(&Q);
    
    enqueue(&Q, start);
    color[start] = 1;
    
    while(!empty_queue(&Q) && is_bipartite) {
        int u = dequeue(&Q);
        
        for(int v = 1; v <= pG->n; v++) {
            if(pG->A[u][v] == 1) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    enqueue(&Q, v);
                }
                else if(color[v] == color[u]) {
                    is_bipartite = 0;
                    return;
                }
            }
        }
    }
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    for(int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    is_bipartite = 1;
    
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            bfs_bipartite(&G, i);
            if(!is_bipartite) break;
        }
    }
    
    if(!is_bipartite) {
        printf("IMPOSSIBLE\n");
    } else {
        int group1[MAX_N], group2[MAX_N];
        int size1 = 0, size2 = 0;
        
        for(int i = 1; i <= n; i++) {
            if(color[i] == color[1]) {
                group1[size1++] = i;
            } else {
                group2[size2++] = i;
            }
        }
        
        for(int i = 0; i < size1; i++) {
            if(i > 0) printf(" ");
            printf("%d", group1[i]);
        }
        printf("\n");
        
        for(int i = 0; i < size2; i++) {
            if(i > 0) printf(" ");
            printf("%d", group2[i]);
        }
        printf("\n");
    }
    
    return 0;
}
--------------------------------------------------------------------------------------------------------------------

Thanh pho co N dia diem 9433
#include <stdio.h>

#define MAX_N 100
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

typedef struct {
    int data[MAX_N];
    int top;
} Stack;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= pG->n; u++)
        for(int v = 1; v <= pG->n; v++)
            pG->A[u][v] = 0;
}

void add_arc(Graph *pG, int u, int v) {
    pG->A[u][v] = 1;
    pG->m++;
}

void make_null_stack(Stack *pS) {
    pS->top = -1;
}

void push(Stack *pS, int x) {
    pS->top++;
    pS->data[pS->top] = x;
}

int pop(Stack *pS) {
    int x = pS->data[pS->top];
    pS->top--;
    return x;
}

int empty_stack(Stack *pS) {
    return pS->top == -1;
}

int num[MAX_N], low[MAX_N];
int on_stack[MAX_N];
int counter;
int scc_count;
Stack S;

void tarjan(Graph *pG, int u) {
    num[u] = low[u] = ++counter;
    push(&S, u);
    on_stack[u] = 1;
    
    for(int v = 1; v <= pG->n; v++) {
        if(pG->A[u][v] == 1) {
            if(num[v] == -1) {
                tarjan(pG, v);
                low[u] = MIN(low[u], low[v]);
            }
            else if(on_stack[v]) {
                low[u] = MIN(low[u], num[v]);
            }
        }
    }
    
    if(num[u] == low[u]) {
        scc_count++;
        int v;
        do {
            v = pop(&S);
            on_stack[v] = 0;
        } while(v != u);
    }
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        if(p == 1) {
            add_arc(&G, a, b);
        } else {
            add_arc(&G, a, b);
            add_arc(&G, b, a);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        num[i] = -1;
        low[i] = -1;
        on_stack[i] = 0;
    }
    counter = 0;
    scc_count = 0;
    make_null_stack(&S);
    
    for(int i = 1; i <= n; i++) {
        if(num[i] == -1) {
            tarjan(&G, i);
        }
    }
    
    if(scc_count == 1) {
        printf("OKIE\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------

Dem so BP lien thong trong DT vo huong 9557
/*===BAT DAU==*/
#include <stdio.h>

#define MAX_N 100

typedef struct {
   int n;
   int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
   pG->n = n;
   for(int u = 1; u <= pG->n; u++)
       for(int v = 1; v <= pG->n; v++)
           pG->A[u][v] = 0;
}

int visited[MAX_N];

void dfs(Graph *pG, int u) {
   visited[u] = 1;
   for(int v = 1; v <= pG->n; v++) {
       if(pG->A[u][v] == 1 && visited[v] == 0) {
           dfs(pG, v);
       }
   }
}

int connected_components(Graph *pG) {
   int count = 0;
   
   for(int i = 1; i <= pG->n; i++) {
       visited[i] = 0;
   }
   
   for(int i = 1; i <= pG->n; i++) {
       if(visited[i] == 0) {
           dfs(pG, i);
           count++;
       }
   }
   
   return count;
}
/*===KET THUC==*/

------------------------------------------------------------------------------------------------------------------------------

Dat nuoc CyberGraph 9606
#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define INF INT_MAX

typedef struct {
    int n;
    int W[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    for(int u = 1; u <= pG->n; u++) {
        for(int v = 1; v <= pG->n; v++) {
            if(u == v) {
                pG->W[u][v] = 0;
            } else {
                pG->W[u][v] = INF;
            }
        }
    }
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->W[u][v] = w;
    pG->W[v][u] = w;
}

int dijkstra(Graph *pG, int s, int t) {
    int dist[MAX_N];
    int visited[MAX_N];
    
    for(int i = 1; i <= pG->n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[s] = 0;
    
    for(int count = 0; count < pG->n; count++) {
        int u = -1;
        int min_dist = INF;
        
        for(int v = 1; v <= pG->n; v++) {
            if(!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }
        
        if(u == -1) break;
        
        visited[u] = 1;
        
        for(int v = 1; v <= pG->n; v++) {
            if(!visited[v] && pG->W[u][v] != INF) {
                if(dist[u] + pG->W[u][v] < dist[v]) {
                    dist[v] = dist[u] + pG->W[u][v];
                }
            }
        }
    }
    
    return dist[t];
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge(&G, u, v, d);
    }
    
    int s, t;
    scanf("%d%d", &s, &t);
    
    int result = dijkstra(&G, s, t);
    printf("%d\n", result);
    
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------

Me cung so 9697
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100
#define INF INT_MAX

int M, N;
int maze[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int isValid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int dijkstra() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            dist[i][j] = INF;
            visited[i][j] = 0;
        }
    }
    
    dist[0][0] = maze[0][0];
    
    for(int count = 0; count < M * N; count++) {
        int min_dist = INF;
        int min_x = -1, min_y = -1;
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j] && dist[i][j] < min_dist) {
                    min_dist = dist[i][j];
                    min_x = i;
                    min_y = j;
                }
            }
        }
        
        if(min_x == -1) break;
        
        visited[min_x][min_y] = 1;
        
        if(min_x == M-1 && min_y == N-1) {
            return dist[M-1][N-1];
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = min_x + dx[dir];
            int ny = min_y + dy[dir];
            
            if(isValid(nx, ny) && !visited[nx][ny]) {
                if(dist[min_x][min_y] + maze[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[min_x][min_y] + maze[nx][ny];
                }
            }
        }
    }
    
    return dist[M-1][N-1];
}

int main() {
    scanf("%d%d", &M, &N);
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    
    int result = dijkstra();
    printf("%d\n", result);
    
    return 0;
}
---------------------------------------------------------------------------------------------------

Duong di ngan nhat 9779
#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_M 500
#define INF INT_MAX

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->edges[pG->m].w = w;
    pG->m++;
}

void bellman_ford(Graph *pG, int s, int pi[], int p[]) {
    for(int i = 1; i <= pG->n; i++) {
        pi[i] = INF;
        p[i] = -1;
    }
    pi[s] = 0;
    
    for(int i = 1; i < pG->n; i++) {
        // Duyệt qua tất cả các cung
        for(int j = 0; j < pG->m; j++) {
            int u = pG->edges[j].u;
            int v = pG->edges[j].v;
            int w = pG->edges[j].w;
            
            if(pi[u] != INF && pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}

int main() {

    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    int pi[MAX_N], p[MAX_N];
    bellman_ford(&G, 1, pi, p);
    
    for(int i = 1; i <= n; i++) {
        if(pi[i] == INF) {
            printf("pi[%d] = oo, p[%d] = -1\n", i, i);
        } else {
            printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
        }
    }
    
    return 0;
}
-------------------------------------------------------------------------------------------------

Floyd-Warshall duong di ngan nhat 9859
#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define INF 999999

typedef struct {
    int n, m;
    int W[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                pG->W[i][j] = 0;
            } else {
                pG->W[i][j] = INF;
            }
        }
    }
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->W[u][v] = w;
    pG->m++;
}

void floyd_warshall(Graph *pG, int dist[][MAX_N]) {
    for(int i = 1; i <= pG->n; i++) {
        for(int j = 1; j <= pG->n; j++) {
            dist[i][j] = pG->W[i][j];
        }
    }
    
    for(int k = 1; k <= pG->n; k++) {
        for(int i = 1; i <= pG->n; i++) {
            for(int j = 1; j <= pG->n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    int dist[MAX_N][MAX_N];
    floyd_warshall(&G, dist);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d -> %d: ", i, j);
            if(dist[i][j] == INF) {
                printf("oo\n");
            } else {
                printf("%d\n", dist[i][j]);
            }
        }
    }
    
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------
Dg di ngan nhat co bien cnt 9941
#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define INF INT_MAX

typedef struct {
    int n, m;
    int W[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                pG->W[i][j] = 0;
            } else {
                pG->W[i][j] = INF;
            }
        }
    }
}

void add_edge(Graph *pG, int u, int v, int w) {
    pG->W[u][v] = w;
    pG->W[v][u] = w;
    pG->m++;
}

void dijkstra_count(Graph *pG, int s, int t, int *shortest_dist, int *count) {
    int dist[MAX_N];
    int cnt[MAX_N];
    int visited[MAX_N];
    
    for(int i = 1; i <= pG->n; i++) {
        dist[i] = INF;
        cnt[i] = 0;
        visited[i] = 0;
    }
    
    dist[s] = 0;
    cnt[s] = 1;
    
    for(int step = 0; step < pG->n; step++) {
        int u = -1;
        int min_dist = INF;
        
        for(int v = 1; v <= pG->n; v++) {
            if(!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }
        
        if(u == -1) break;
        
        visited[u] = 1;
        
        for(int v = 1; v <= pG->n; v++) {
            if(!visited[v] && pG->W[u][v] != INF) {
                if(dist[u] + pG->W[u][v] < dist[v]) {
                    dist[v] = dist[u] + pG->W[u][v];
                    cnt[v] = cnt[u];
                }
                else if(dist[u] + pG->W[u][v] == dist[v]) {
                    cnt[v] += cnt[u];
                }
            }
        }
    }
    
    if(dist[t] == INF) {
        *shortest_dist = -1;
        *count = 0;
    } else {
        *shortest_dist = dist[t];
        *count = cnt[t];
    }
}

int main() {
    Graph G;
    int n, m;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for(int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    int shortest_dist, count;
    dijkstra_count(&G, 1, n, &shortest_dist, &count);
    
    printf("%d %d\n", shortest_dist, count);
    
    return 0;
}
--------------------------------------------------------------------------------------------------------------------

Quan ly du an phan mem anh tuan 10046

#include <stdio.h>
#include <stdbool.h>
#define maxv 50
#define idx 100
#define oo 9999999
typedef int Vertices;

typedef struct{
   int matrix[maxv][maxv];
   Vertices n;
}Graph;

typedef struct{
   int data[idx];
   int size;
}List;

void makenullList(List *l){
   l->size=0;
}

bool emptyList(List *l){
   return (l->size==0);
}

void pushList(List *l, int element){
   l->data[l->size] = element;
   l->size++;
}

int getList(List *l, int index){
   return l->data[index-1];
}

void initGraph(Graph *g, int n){
   g->n=n;
   for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
           g->matrix[i][j]=0;
}

void addEdge(Graph *g, int x, int y){
   g->matrix[x][y]=1;
}

bool adjacent(Graph *g, int x, int y){
   return g->matrix[x][y]==1;
}

int degreeInput(Graph *g, int x){
   int count=0;
   for(int i=1;i<=g->n;i++){
       if(adjacent(g,i,x)){
           count++;
       }
   }
   return count;
}

int degreeOutput(Graph *g, int x){
   int count=0;
   for(int i=1;i<=g->n;i++){
       if(adjacent(g,x,i)){
           count++;
       }
   }
   return count;
}

List neighbors(Graph *g, int x){
   List L;
   makenullList(&L);
   for(int i=1;i<=g->n;i++){
       if(adjacent(g,x,i)){
           pushList(&L,i);
       }
   }
   return L;
}

void copyList(List *l1, List *l2){
   makenullList(l1);
   for(int i=1;i<=l2->size;i++){
       int value = getList(l2,i);
       pushList(l1,value);
   }
}

int rank[maxv];
int d[maxv];
List L1,L2;
int k=0;

List topoSort(Graph *g){
   List toposort;
   makenullList(&toposort);
   int u,n=g->n;
   for(u=1;u<=n;u++) d[u]=0;
   for(u=1;u<=n;u++) d[u] = degreeInput(g,u);
   makenullList(&L1);
   for(u=1;u<=n;u++) if(d[u]==0) pushList(&L1,u);
   while(!emptyList(&L1)){
       makenullList(&L2);
       for(int i=1;i<=L1.size;i++){
           int u = getList(&L1,i);
           rank[u] = k;
           pushList(&toposort,u);
           List L = neighbors(g,u);
           for(int j=1;j<=L.size;j++){
               int v = getList(&L,j);
               d[v]--;
               if(d[v]==0){
                   pushList(&L2,v);
               }
           }
       }
       copyList(&L1,&L2);
       k++;
   }
   return toposort;
}

int min(int a, int b){
   return (a<b)?a:b;
}

int max(int a, int b){
   return (a>b)?a:b;
}

int main(){
   Graph g;
   int n, u, x;
   scanf("%d", &n);
   initGraph(&g, n+2); 
   int time[100]; 
   time[n+1] = 0; 
   for (u=1;u<=n;u++) {
       scanf("%d",&time[u]); 
       do{
           scanf("%d", &x); 
           if(x>0){ 
             addEdge(&g, x, u);   
           } 
       }while(x>0);
   }
   
   for(int i=1;i<=n;i++){
       if(degreeInput(&g,i)==0){
           addEdge(&g,n+1,i);
       }
   }
   
   for(int i=1;i<=n;i++){
       if(degreeOutput(&g,i)==0){
           addEdge(&g,i,n+2);
       }
   }

   List L = topoSort(&g);
   
   int t[100];
   int T[100];
   
   t[n+1] = 0; 
   for (int j=2;j<=L.size;j++){ 
       int u = getList(&L,j); 
       t[u] = -1; 
       for (x=1;x<=g.n;x++){
           if (adjacent(&g,x,u)){ 
               t[u] = max(t[u], t[x] + time[x]); 
           }
       }
   }
   
   T[n+2] = t[n+2]; 
   for (int j=L.size-1;j>=1;j--) { 
       int u = getList(&L, j); 
       T[u] = oo; 
       for (int v = 1; v <= g.n; v++){
           if (adjacent(&g,u,v)){ 
               T[u] = min(T[u], T[v] - time[u]); 
           }
       }
   }
   
   int a,b; 
   scanf("%d%d",&a,&b);
   
   if(b>= t[a] && b<= T[a]) printf("YES"); 
   else printf("NO"); 
   
   return 0;
}
-------------------------------------------------------------------------------------------------------------------

Du an xay nha 10244
`#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_DEPS 10

typedef struct {
    int duration;
    int dependencies[MAX_DEPS];
    int dep_count;
    int earliest_start;
    int earliest_finish;
    int latest_start;
    int latest_finish;
} Task;

void calculate_earliest_times(Task tasks[], int n) {
    int changed = 1;
    
    // Khởi tạo
    for (int i = 0; i < n; i++) {
        tasks[i].earliest_start = 0;
        tasks[i].earliest_finish = tasks[i].duration;
    }
    
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            int max_dep_finish = 0;
            
            // Tìm thời gian hoàn thành muộn nhất của các công việc phụ thuộc
            for (int j = 0; j < tasks[i].dep_count; j++) {
                int dep_index = tasks[i].dependencies[j];
                if (tasks[dep_index].earliest_finish > max_dep_finish) {
                    max_dep_finish = tasks[dep_index].earliest_finish;
                }
            }
            
            int new_earliest_start = max_dep_finish;
            int new_earliest_finish = new_earliest_start + tasks[i].duration;
            
            if (new_earliest_start != tasks[i].earliest_start || 
                new_earliest_finish != tasks[i].earliest_finish) {
                tasks[i].earliest_start = new_earliest_start;
                tasks[i].earliest_finish = new_earliest_finish;
                changed = 1;
            }
        }
    }
}

void calculate_latest_times(Task tasks[], int n, int project_duration) {
    int changed = 1;
    
    // Khởi tạo
    for (int i = 0; i < n; i++) {
        tasks[i].latest_finish = project_duration;
        tasks[i].latest_start = project_duration - tasks[i].duration;
    }
    
    // Tìm các task kết thúc (không có task nào phụ thuộc vào nó)
    int is_end[MAX_TASKS] = {1}; // Mặc định là end task
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tasks[i].dep_count; j++) {
            is_end[tasks[i].dependencies[j]] = 0;
        }
    }
    
    // Set latest times cho end tasks
    for (int i = 0; i < n; i++) {
        if (is_end[i]) {
            tasks[i].latest_finish = tasks[i].earliest_finish;
            tasks[i].latest_start = tasks[i].earliest_start;
        }
    }
    
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            if (is_end[i]) continue; // Skip end tasks
            
            int min_successor_start = project_duration;
            
            // Tìm các công việc phụ thuộc vào công việc i
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < tasks[j].dep_count; k++) {
                    if (tasks[j].dependencies[k] == i) {
                        if (tasks[j].latest_start < min_successor_start) {
                            min_successor_start = tasks[j].latest_start;
                        }
                        break;
                    }
                }
            }
            
            int new_latest_finish = min_successor_start;
            int new_latest_start = new_latest_finish - tasks[i].duration;
            
            if (new_latest_finish != tasks[i].latest_finish || 
                new_latest_start != tasks[i].latest_start) {
                tasks[i].latest_finish = new_latest_finish;
                tasks[i].latest_start = new_latest_start;
                changed = 1;
            }
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int n;
    
    // Đọc số lượng task
    scanf("%d", &n);
    
    // Đọc thông tin từng task
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i].duration);
        
        tasks[i].dep_count = 0;
        int dep;
        while (scanf("%d", &dep) == 1 && dep != 0) {
            tasks[i].dependencies[tasks[i].dep_count] = dep - 1; // Convert to 0-based index
            tasks[i].dep_count++;
        }
    }
    
    // Tính toán thời gian sớm nhất
    calculate_earliest_times(tasks, n);
    
    // Tìm thời gian hoàn thành dự án
    int project_duration = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i].earliest_finish > project_duration) {
            project_duration = tasks[i].earliest_finish;
        }
    }
    
    // Tính toán thời gian trễ nhất
    calculate_latest_times(tasks, n, project_duration);
    
    // Output kết quả
    printf("%d\n", project_duration);
    
    for (int i = 0; i < n; i++) {
        printf("%d-%d\n", tasks[i].earliest_start, tasks[i].latest_start);
    }
    
    // Thêm 2 dòng cuối theo yêu cầu của hệ thống
    printf("0-0\n");
    printf("%d-%d\n", project_duration, project_duration);
    
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------



