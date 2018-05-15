#include <stdio.h>
int nim[10];
int next[10]={1,2,3,4,5,6,7,8,9,-1};
int head = -1;
int ava = 0;

int cari(int panjangArray)
{
	int nyari = -1;
	int i=0;
	bool ketemu = false;
	while(i<panjangArray && ketemu==false)
	{
		if(next[i]==nyari)
		{
			ketemu = true;
		}
		else i++;
	}
	
	if(ketemu == true)
	{
		return(i);
	}else
		{
			return(-1);
		}
}
void cetak()
{
	int i=head;
	if(head==-1)
	{
		printf("Data kosong");
	}
	else{
		while(i!=-1)
		{
		printf("%d ", nim[i]);
		i = next[i];
		}
	}

}
void tambah2(int jumlah)
{
	
	int tmp;
	int tambah;
	int tmp2;
	printf("Masukkan Data yang ingin ditambahkan :");
	scanf("%d", &tambah);
	if(head==-1)
	{
		nim[ava]=tambah;
		tmp = ava;
		head = ava;
		ava = next[ava];
		next[tmp]=-1;
	}
	else
		{
			tmp2 = cari(jumlah);
			nim[ava] = tambah;
			tmp = ava;
			ava = next[ava];
			next[tmp]=-1;
			next[tmp2]=tmp;
			
		}
}
int cariAngka(int cari,int panjangArray)
{
	int i=0;
	bool ketemu = false;
	while(i<panjangArray && ketemu==false)
	{
		if(nim[i]==cari)
		{
			ketemu = true;
		}
		else i++;
	}
	if(ketemu == true)
	{
		return(i);
	}else
		{
			return(-1);
		}
}
void kurang(int jumlah)
{
	int tmp2;
	int tmp;
	int tmp3;
	int tmp4;
	int kurang;
	printf("Masukkan Data yang ingin dikurang :");
	scanf("%d", &kurang);
	if(cariAngka(kurang,jumlah)!=head)
	{
	tmp=cariAngka(kurang,jumlah);
	nim[tmp] = NULL;
	tmp2 = next[tmp];
	next[tmp]=ava;
	next[tmp-1]=tmp2;
	ava=tmp;
	
	}
	else{
		tmp=cariAngka(kurang,jumlah);
		nim[tmp]=NULL;
		tmp2=next[tmp];
		next[tmp]=ava;
		tmp3=head;
		head=tmp2;
		ava=tmp3;
	}
	
	
	
}
main()
{
	int jumlah=0;
	int pil;
	printf("Menu :\n");
	printf("1. Tambah Data\n");
	printf("2. Kurang Data\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	printf("Pilih :");
	
	scanf("%d", &pil);	
	
	while(pil!=4)
	{	
		switch(pil)
		{
			case 1 :{
					tambah2(jumlah);
					jumlah++;
				break;
			}break;
			case 2 :{
					kurang(jumlah);
					jumlah--;
				break;
			}break;
			case 3:{cetak();
				break;
			}break;
			
		}
	
		printf("\nMenu :\n");
		printf("1. Tambah Data\n");
		printf("2. Kurang Data\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf("Pilih :");
		
		scanf("%d", &pil);	
	}
	
}
