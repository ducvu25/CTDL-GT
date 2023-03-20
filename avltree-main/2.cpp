#include<stdio.h>
#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;

#define RH 1 // cây con ph?i cao hon ( lech phai )
#define EH 0 // cây con trái b?ng cây con ph?i ( cân bang )
#define LH -1 // cây con trái cao hon ( lech trái )

typedef int ItemType; // khai báo ItemType có ki?\eu int

struct AVLNode
{
	int balFactor; // chỉ số cân bằng
	ItemType Info;
	AVLNode* Right;
	AVLNode* Left;
};

typedef struct AVLNode* AVLTree;

// khoi tao danh sach rỗng
void CreateAVLTree(AVLTree& T)
{
	T = NULL;
}

// khoi tao node
AVLNode* CreateAVLNode(int x)
{
	AVLNode* p = new AVLNode;

	if (p == NULL)
	{
		cout << "\nkhong du bo nho de cap phat!\n";
		return NULL;
	}
	// goc ( root ) // node dau tiên
	p->balFactor = EH;
	p->Info = x;
	p->Left = NULL; // chua có cây
	p->Right = NULL; // chua có cây

	return p;
}

void rotateLL(AVLTree& T) // quay don LL
{
	AVLNode* T1 = T->Left;
	T->Left = T1->Right;
	T1->Right = T;
	switch (T1->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
	T = T1;
}

void rotateRR(AVLTree& T) // quay don RR
{
	AVLNode* T1 = T->Right;
	T->Right = T1->Left;
	T1->Left = T;
	switch (T1->balFactor)
	{
	case RH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = RH;
		T1->balFactor = LH;
		break;
	}
	T = T1;
}

void rotateLR(AVLTree& T) // quay kép LR
{
	AVLNode* T1 = T->Left;
	AVLNode* T2 = T1->Right;
	T->Left = T2->Right;
	T2->Right = T;
	T1->Right = T2->Left;
	T2->Left = T1;
	switch (T2->balFactor)
	{
	case LH:
		T->balFactor = RH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH:
		T->balFactor = EH;
		T1->balFactor = LH;
		break;
	}
	T2->balFactor = EH;
	T = T2;
}

void rotateRL(AVLTree& T) // quay kép RL
{
	AVLNode* T1 = T->Right;
	AVLNode* T2 = T1->Left;
	T->Right = T2->Left;
	T2->Left = T;
	T1->Left = T2->Right;
	T2->Right = T1;
	switch (T2->balFactor)
	{
	case RH:
		T->balFactor = LH; T1->balFactor = EH; break;
	case EH:
		T->balFactor = EH; T1->balFactor = EH; break;
	case LH:
		T->balFactor = EH; T1->balFactor = RH; break;
	}
	T2->balFactor = EH;
	T = T2;
}

int balanceLeft(AVLTree& T)
{
	// cân bằng khi cây bi lệch về bên trái
	AVLNode* T1 = T->Left;

	switch (T1->balFactor)
	{
	case LH: rotateLL(T); return 2;
	case EH: rotateLL(T); return 1;
	case RH: rotateLR(T); return 2;
	}
	return 0;
}

int balanceRight(AVLTree& T)
{
	// cân bằng khi cây bi lệch về bên phải
	AVLNode* T1 = T->Right;

	switch (T1->balFactor)
	{
	case LH: rotateRL(T); return 2;
	case EH: rotateRR(T); return 1;
	case RH: rotateRR(T); return 2;
	}
	return 0;
}

int balance(AVLTree& T)
{
	int bf = T->balFactor;

	if (bf == LH)
	{
		AVLNode* T1 = T->Left;
		switch (T1->balFactor)
		{
		case LH: rotateLL(T); return 2;
		case EH: rotateLL(T); return 1;
		case RH: rotateLR(T); return 2;
		}
	}
	else if (bf == RH)
	{
		AVLNode* T1 = T->Right;
		switch (T1->balFactor)
		{
		case LH: rotateRL(T); return 2;
		case EH: rotateRR(T); return 1;
		case RH: rotateRR(T); return 2;
		}
	}

	return 0;
}
// thêm một phần tử trên cây AVL
int InsertNode(AVLTree& T, int x)
{
	int Res;
	if (T)
	{
		//gia tri da co trong cay
		if (T->Info == x) return 0;

		//T->Info > x
		//chen vao ben trai
		if (T->Info > x)
		{
			Res = InsertNode(T->Left, x);
			if (Res < 2) return Res;

			//Res >= 2
			switch (T->balFactor)
			{
			case RH:
				T->balFactor = EH;
				return 1;
			case EH:
				T->balFactor = LH;
				return 2;
			case LH:
				balanceLeft(T);
				return 1;
			}
		}

		//T->Info < x
		//chen vao ben phai
		else
		{
			Res = InsertNode(T->Right, x);

			if (Res < 2) return Res;

			//Res >= 2
			switch (T->balFactor)
			{
			case LH:
				T->balFactor = EH;
				return 1;
			case EH:
				T->balFactor = RH;
				return 2;
			case RH:
				balanceRight(T);
				return 1;
			}
		}
	}
	T = CreateAVLNode(x);
	return 2;
}
///tim x match voi node
//Tim node the mang
int searchstandfor(AVLNode*& p, AVLNode*& q) // Tìm ki?m giá tr? c?n xóa
{
	int ketqua;
	if (q->Left != NULL) ///n?u con tr? di qua trái khác r?ng thì k?t qu? s? b?ng k?t qu? tìm ki?m ? trái
	{
		ketqua = searchstandfor(p, q->Left); // K?t qu? b?ng giá tr? Node q bên trái
		if (ketqua < 2)
			return ketqua;   // N?u giá tr? tìm th?y thì tr? v? 1 còn không ti?p t?c tìm ki?m 
		switch (q->balFactor)  // Xét v? giá tr? chi?u cao cây Node q
		{
		case LH:			// N?u Node q bên  trái l?ch cao hon thì ti?p t?c tìm ki?m bên ph?i
			q->balFactor = EH;
			return 2;
		case EH:		// N?u cây con trái b?ng v?i cây con ph?i thì d?ng tìm ki?m bên ph?i và qua tìm ki?m bên trái.
			q->balFactor = RH;
			return 1;
		case RH:		// N?u Node q bên ph?i l?nh cao hon thì cân b?ng l?i node q bên ph?i
			return balanceRight(q);
		}
	}
	else  // N?u dò d?n lúc h?t giá tr?
	{
		p->Info = q->Info; // Giá tr? Node p = Giá tr? Node q;
		p = q; // Node p = Node q;
		q = q->Right;  // Node q s? b?ng bên ph?i c?a Node q;
	}
	return 2; // Ti?p t?c tìm ki?m.
}
// tìm node trái cùng
AVLNode* minValueNode(AVLNode* T){ 
	if(T->Left == NULL)
		return T;
	return T->Left;
}
int getHeight(AVLNode* T) {
    // Nếu cây rỗng, trả về 0
    if (T == NULL) {
        return 0;
    }
    // Nếu cây không rỗng, tính chiều cao của cây con trái và cây con phải
    int leftHeight = getHeight(T->Left);
    int rightHeight = getHeight(T->Right);
    // Trả về chiều cao của cây con lớn nhất, cộng thêm 1 để tính chiều cao của cây hiện tại
    return max(leftHeight, rightHeight) + 1;
}

int getBalance(AVLNode* T) { // trả về độ cân bằng
    if (T == NULL) return 0;          // nếu nút là NULL thì trả về 0
    return getHeight(T->Left) - getHeight(T->Right);    // trả về hiệu chiều cao cây con trái và cây con phải
}
///xoa node
AVLNode* deleteAVLNode(AVLNode* T, ItemType x) {
    if (T == NULL) return T; // node rỗng - không tìm thấy
    if (x < T->Info) T->Left = deleteAVLNode(T->Left, x); // xóa ở bên trái
    else if (x > T->Info) T->Right = deleteAVLNode(T->Right, x); // xóa bên phải
    else { // tìm thấy node cần xóa
        if (T->Left == NULL || T->Right == NULL) {
            AVLNode* temp = T->Left ? T->Left : T->Right;
            if (temp == NULL) {
                temp = T;
                T = NULL;
            } else 
				*T = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(T->Right); // tìm node trái cùng của node bên phải
            T->Info = temp->Info;
            T->Right = deleteAVLNode(T->Right, temp->Info);
        }
    }
    if (T == NULL) return T;

    T->balFactor = getBalance(T);
	if(T->balFactor != 0){ // Neesu khong can bang
		balance(T);
	}
    return T;
}
/*
test
1
50
23
24
70
-999
2
3
23
2
*/
/*
int deleteAVLNode(AVLNode*& T, ItemType x) // Xóa giá tr? c?n tìm
{
	int ketqua;
	if (T == NULL) // N?u Cây T r?ng thì tr? v? không có giá tr?
		return 0;
	if (T->Info > x) // N?u Giá tr? T l?n hon giá tr? x c?n tìm
	{
		ketqua = deleteAVLNode(T->Left, x); // Ti?p t?c tìm phía bên trái Node T
		if (ketqua < 2)
			return ketqua;  // N?u k?t qu? nh? hon 2 => tr? v? giá tr? tìm th?y
		switch (T->balFactor)
		{
		case LH:		// N?u Node T bên  trái l?ch cao hon thì ti?p t?c tìm ki?m bên ph?i
			T->balFactor = EH;
			return 2;
		case EH:		// N?u cây con trái b?ng v?i cây con ph?i thì d?ng tìm ki?m bên ph?i và qua tìm ki?m bên trái						
			T->balFactor = RH;
			return 1;
		case RH:		// N?u Node T bên ph?i l?nh cao hon thì cân b?ng l?i node T bên ph?i
			return balanceRight(T);

		}
	}
	else if (T->Info < x) // N?u giá tr? node T nh? hon x 
	{
		ketqua = deleteAVLNode(T->Right, x); // giá tr? k?t qu? gán tìm ki?m ti?p bên tay ph?i
		if (ketqua < 2)
			return ketqua;	// N?u k?t qu? tìm th?y s? d?ng l?i 
		switch (T->balFactor)
		{
		case RH:	// N?u Node T bên  ph?i l?ch cao hon thì ti?p t?c tìm ki?m bên ph?i
			T->balFactor = EH;
			return 2;
		case EH:	// N?u cây con trái b?ng v?i cây con ph?i thì d?ng tìm ki?m bên ph?i và qua tìm ki?m bên trái	
			T->balFactor = LH;
			return 1;
		case LH:	//  N?u Node T bên ph?i l?nh cao hon thì cân b?ng l?i node T bên trái 
			return balanceLeft(T);
		}
	}
	else //Tim thay
	{
		if (T->Left == NULL) // Xét di?u ki?n n?u Node T bên trái b?ng R?ng
		{
			T = T->Right; //  Node T = Node T bên ph?i
			ketqua = 2; // Tr? v? k?t qu? b?ng 2
		}
		else // Còn n?u không r?ng thì
		{
			if (T->Right == NULL) // Xét Ði?u ki?n Node T bên ph?i b?ng R?ng
			{
				T = T->Left; //  Node T = Node T bên trái
				ketqua = 2; // Tr? v? k?t qu? b?ng 2
			}
			else // Còn n?u ko th?y
			{
				ketqua = searchstandfor(T, T->Right); // Xét k?t qu? tìm ki?m giá tr? bên ph?i
				if (ketqua < 2)
					return ketqua; // N?u k?t qu? tìm th?y s? d?ng l?i 
				switch (T->balFactor)
				{
				case RH: // N?u Node T bên  ph?i l?ch cao hon thì ti?p t?c tìm ki?m bên ph?i
					T->balFactor = EH;
					return 2;
				case EH: // N?u cây con trái b?ng v?i cây con ph?i thì d?ng tìm ki?m bên ph?i và qua tìm ki?m bên trái
					T->balFactor = LH;
					return 1;
				case LH: //  N?u Node T bên ph?i l?nh cao hon thì cân b?ng l?i node T bên trái 
					return balanceLeft(T);
				}
			}
		}
		delete T; // Xóa giá tr? Node p dó;
		return ketqua; // Tr? v? giá tr? k?t qu? d? xét di?u ki?n dã xóa dc hay chua
	}
	return ketqua; // Tr? v? giá tr? k?t qu? d? xét di?u ki?n dã xóa dc hay chua 
}
*/

//Duyet theo muc
void Level(AVLTree T)
{
	queue<AVLTree> q;
	AVLTree p;

	if (T == NULL) return;

	p = T;
	q.push(p);

	while (!q.empty())
	{
		p = q.front();
		q.pop();
		cout << p->Info << endl;

		if (p->Left) q.push(p->Left);
		if (p->Right) q.push(p->Right);
	}
}
void traverseNLR(AVLNode* root)
{
	if (root == NULL)
		return;
	cout << root->Info << " ";
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
AVLNode* findTNode(AVLNode* root, ItemType x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root;
	else if (root->Info > x)
		return findTNode(root->Left, x);
	else
		return findTNode(root->Right, x);
}

void displayMenu()
{
	cout << "\n=== MENU ===" << endl;
	cout << "1. Tao Node " << endl;
	cout << "2. Xuat Node " << endl;
	cout << "3. Xoa Node " << endl;
	cout << "4. Tim Node" << endl;
	cout << "5. Thoat" << endl;
	cout << "vui long nhap lua chon (1-5): ";
}

int main()
{
	AVLTree T;
	CreateAVLTree(T);
	int luachon;
	do
	{
		displayMenu();
		cout << "Vui long nhap lua chon" << endl;
		cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			int value;
			char c;
			do{
				cout << "Nhap node: ";
				cin >> value;
				InsertNode(T, value);
				cout << "Ban muon nhap tiep khong(y/n)?\n";
				cout << "Lua chon: ";
				cin >> c;
			} while (c != 'n');
			break;
		}
		case 2:
		{
			cout << "Xuat cay theo tung node lan luot theo NLR la:" << endl;
			traverseNLR(T);
			break;
		}
		case 3:
		{
			int value;
			cout << "Nhap gia tri de xoa" << endl;
			cin >> value;
			if (deleteAVLNode(T, value))
				cout << "Xoa thanh cong" << endl;
			else
				cout << "Gia tri chua tim thay" << endl;
			break;
		}
		case 4:
		{
			int value;
			cout << "Tim Node" << endl;
			cin >> value;
			if (findTNode(T, value) != NULL)
				cout << "Gia tri " <<value << " tim thay cua tren cay \n";
			else
				cout << "Gia tri khong ton tai\n";
			break;
		}
		case 5:
		{
			exit(1);
			break;
		}
		default:{
			cout << "Lua chon khong hop le!\n";
		}
		}
	} while (1);
	//_getch();
}
