#include<iostream>
using namespace std;
#include<math.h>
#define Max 100
aaa
bbb

void Nhapmatran(int a[][Max], int &m, int &n);
void Xuatmatran(int a[][Max], int m, int n);
void congMaTran(int a[][Max], int b[][Max], int m, int n);
void truMaTran(int a[][Max], int b[][Max], int m, int n);
void multiply(int a[][Max], int b[][Max], int c[][Max], int m, int n, int p, int q);
void congtrunhanmatran();
void swap_rows(double matrix[Max][Max], int row1, int row2, int num_cols);
void print_matrix(double matrix[Max][Max], int num_rows, int num_cols);
void row_echelon_form(double matrix[Max][Max], int num_rows, int num_cols);
void find_solution(double matrix[Max][Max], int num_rows, int num_cols);
void reduce();
double timDetCuaMaTran(double a[Max][Max], int size);
void timMaTranChuyenVi(double maTranAdj[Max][Max], double maTranChuyenVi[Max][Max], int size);
void timMaTranAdj(double a[Max][Max], double maTranAdj[Max][Max], int size);
int timMaTranNghichDao(double a[Max][Max], int size);
void inverse();
void menu();

int main(){
    int choice;
    menu();
    printf("\nYour choice: ");
    scanf("%d", &choice);
    while (choice >= 1 && choice <= 3) { 
        switch (choice){
            case 1:
                congtrunhanmatran();
                break;
            case 2:
                reduce();
                break;
            case 3:
                inverse();
                break;
        }
        menu();
        printf("\nYour choice: ");
        scanf("%d", &choice);
    }
    printf("\nCam on da su dung chuong trinh ^^");
}

void Nhapmatran(int a[][Max], int &m, int &n)
{
    int i,j;
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &m);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &n);
    printf("Hay nhap vao ma tran: \n");
    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuatmatran(int a[][Max], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        printf("[  ");
        for(j=0; j < n; j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("]\n");
    }
}

void congMaTran(int a[][Max], int b[][Max], int m, int n)
{
    int c[Max][Max];
    int i, j;
    for(i = 0 ; i < m ; i++)
    {
        for(j = 0;j < n ; j++)
        {
            c[i][j] = a[i][j] + b[i][j];   
        }
    }
    printf("\nKet qua cua phep cong hai ma tran la: \n\n");
    Xuatmatran(c, m, n);
}

void truMaTran(int a[][Max], int b[][Max], int m, int n)
{
    int d[Max][Max];
    int i, j;
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0;j < m ; j++)
        {
            d[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\nKet qua cua phep tru hai ma tran la:\n\n");
    Xuatmatran(d, n, m);
}

void multiply(int a[][Max], int b[][Max], int c[][Max], int m, int n, int p, int q) 
{
    int i, j, k;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < q; ++j) {
            c[i][j] = 0;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < q; ++j) {
            for (k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nThe product of the two matrices is:-\n\n");
    Xuatmatran(c, m, q);
}

void menu()
{
    printf("-----------MENU------------");
    printf("\n1 - Cong, Tru, Nhan 2 ma tran.\n");
    printf("2 - Tim reduce-echelon matrix.\n");
    printf("3 - Tim ma tran nghich dao.\n");
    printf("4 - Quit.\n");
}


void congtrunhanmatran() {
    int a[Max][Max], b[Max][Max],c[Max][Max];
    int n,m;
    int x,y;
    nhaplai:
    printf("\n1- Matrix addition");
    printf("\n2- Matrix Subtraction");
    printf("\n3- Matrix Multiplication");
    printf("\n0- Exit\n");
    int chon;
    do
    {
        printf("\nYour choice: ");
        scanf("%d", &chon);
        if(chon > 3 || chon < 0)
        {
            printf("\nLoi xin hay nhap lai.");
        }
        else if (chon == 0) {
            printf("\nBan se tro ve menu chinh\n\n");
            break;
        }
    } while (chon > 3 || chon < 0);
    if(chon == 1)
    {
        printf("\nMa tran A: \n");
        Nhapmatran(a,m,n);
        printf("\nMa tran B: \n");
        Nhapmatran(b,m,n);
        congMaTran(a,b,m,n);
        goto nhaplai;
    }
    else if(chon == 2)
    {
        printf("\nMa tran A: \n");
        Nhapmatran(a, m, n);
        printf("\nMa tran B: \n");
        Nhapmatran(b, m, n);
        truMaTran(a, b, n, m);
        goto nhaplai;
    }
    else if(chon == 3)
    {
        Nhaplai:
        printf("\nMa tran A: \n");
        Nhapmatran(a, m, n);
        printf("\nMa tran B: \n");
        Nhapmatran(b, x, y);
        if(n != x)
        {
            printf("So hang cua ma tran A khong bang so cot cua ma tran B");
            printf("\nXin hay nhap lai.");
            goto Nhaplai;
        }
        multiply(a,b,c,m,n,x,y);
        goto nhaplai;
    }
}

void reduce(){
    int num_rows, num_cols;

    printf("\nNhap so hang cua ma tran: ");
    scanf("%d", &num_rows);

    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &num_cols);

    double matrix[Max][Max];

    printf("Hay nhap vao ma tran: \n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("\nTruoc khi chuyen doi:\n\n");

    print_matrix(matrix, num_rows, num_cols);

    row_echelon_form(matrix, num_rows, num_cols);

    printf("\nSau khi chuyen doi:\n\n");
    print_matrix(matrix, num_rows, num_cols);

    printf("\nSolution:\n");
    find_solution(matrix, num_rows, num_cols);
    printf("\nBan se tro ve menu chinh\n\n");
}

void swap_rows(double matrix[Max][Max], int row1, int row2, int num_cols) {
    for (int col = 0; col < num_cols; col++) {
        double temp = matrix[row1][col];
        matrix[row1][col] = matrix[row2][col];
        matrix[row2][col] = temp;
    }
}

void print_matrix(double matrix[Max][Max], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        printf("[  ");
        for (int j = 0; j < num_cols; j++) {
            printf("%.2f  ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void row_echelon_form(double matrix[Max][Max], int num_rows, int num_cols) {
    int lead = 0;
    for (int r = 0; r < num_rows; r++) {
        if (lead >= num_cols)
            return;
        int i = r;
        while (matrix[i][lead] == 0.0) {
            i++;
            if (i == num_rows) {
                i = r;
                lead++;
                if (lead == num_cols)
                    return;
            }
        }
        swap_rows(matrix, i, r, num_cols);
        double divisor = matrix[r][lead];
        if (divisor != 0.0) {
            for (int j = 0; j < num_cols; j++)
                matrix[r][j] /= divisor;
        }
        for (int k = 0; k < num_rows; k++) {
            if (k != r) {
                double factor = matrix[k][lead];
                for (int j = 0; j < num_cols; j++)
                    matrix[k][j] -= factor * matrix[r][j];
            }
        }
        lead++;
    }
}

void find_solution(double matrix[Max][Max], int num_rows, int num_cols) {
    for (int r = 0; r < num_rows; r++) {
        int pivot_col = -1;
        for (int c = 0; c < num_cols - 1; c++) {
            if (matrix[r][c] != 0) {
                pivot_col = c;
                break;
            }
        }

        if (pivot_col != -1) {
            printf("x%d = %.2f\n", pivot_col + 1, matrix[r][num_cols - 1]);
        } else {
            int last_col = num_cols - 1;
            if (matrix[r][last_col] != 0) {
                printf("No solution exists.\n");
                return;
            }
        }
    }
}

void inverse() {
    double a[Max][Max];
    int size;
    Again:
    printf("\nNhap kich thuoc ma tran vuong: ");
    scanf("%d", &size);

    printf("Nhap cac phan tu cua ma tran: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    if(timMaTranNghichDao(a, size) == 0) {
        printf("\nHay nhap lai:");
        goto Again;
    }
    printf("\nBan se tro ve menu chinh\n\n");
}

double timDetCuaMaTran(double a[Max][Max], int size) {
    if (size == 1) {
        return a[0][0];
    }
    double det = 0;
    double maTranPhu[Max][Max];
    int dau = 1, dongPhu, cotPhu = 0;

    for (int cot = 0; cot < size; cot++) {
        dongPhu = 0;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j != cot) {
                    maTranPhu[dongPhu][cotPhu] = a[i][j];
                    cotPhu++;
                }
            }
            dongPhu++;
            cotPhu = 0;
        }
        double detMaTranPhu = timDetCuaMaTran(maTranPhu, size - 1);
        det += dau * a[0][cot] * detMaTranPhu;
        dau = -dau;
    }
    return det;
}

void timMaTranChuyenVi(double maTranAdj[Max][Max], double maTranChuyenVi[Max][Max], int size) {
    for (int dong = 0; dong < size; dong++) {
        for (int cot = 0; cot < size; cot++) {
            maTranChuyenVi[dong][cot] = maTranAdj[cot][dong];
        }
    }
}

void timMaTranAdj(double a[Max][Max], double maTranAdj[Max][Max], int size) {
    double temp[Max][Max], maTranC[Max][Max];
    int dongC = 0, cotC = 0, dau = 1;
    for (int dong = 0; dong < size; dong++) {
        for (int cot = 0; cot < size; cot++) {
            dongC = 0;
            for (int i = 0; i < size; i++) {
                cotC = 0;
                for (int j = 0; j < size; j++) {
                    if (i == dong || j == cot) continue;
                    temp[dongC][cotC] = a[i][j];
                    cotC++;
                }
                if(i != dong) dongC++;
            }
            maTranC[dong][cot] = pow(-1, dong + cot) * timDetCuaMaTran(temp, size - 1);
        }
    }
    timMaTranChuyenVi(maTranC, maTranAdj, size );
}

int timMaTranNghichDao(double a[Max][Max], int size) {
    double maTranNghichDao[Max][Max], maTranAdj[Max][Max];
    timMaTranAdj(a, maTranAdj, size);
    if (timDetCuaMaTran(a, size) == 0) {
        printf("Ma tran khong kha nghich\n");
        return 0;
    }
    else {
        printf("\nDay la ma tran kha nghich cua ma tran tren:\n\n");
        for (int dong = 0; dong < size; dong++) {
            printf("[");
            for (int cot = 0; cot < size; cot++) {
                maTranNghichDao[dong][cot] = maTranAdj[dong][cot] / timDetCuaMaTran(a, size);
                printf("%.2lf ", maTranNghichDao[dong][cot]);
            }
            printf("]\n");
        }
    }
}
