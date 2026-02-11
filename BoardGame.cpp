#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
    srand(time(NULL));
    int oyunTahtasi[9][9];
    int i, j;
    int OPsayisi=8;
    int BPsayisi=8;
    int yerlesen1=0;
    int yerlesen2=0;

    for(i=0; i<9; i++){
        for (j=0; j<9; j++){
            oyunTahtasi[i][j] = 0;
        }
    }

    while(yerlesen1<OPsayisi){
        int satir=rand()%9;
        int sutun=rand()%9;
        if(oyunTahtasi[satir][sutun]==0){
            oyunTahtasi[satir][sutun]=1;
            yerlesen1++;
        }
    }
   while(yerlesen2<BPsayisi){
        int satir=rand()%9;
        int sutun=rand()%9;
        
        if(oyunTahtasi[satir][sutun]==0){
            int cakisma=0;
            
            if(satir>0 && sutun>0 && oyunTahtasi[satir-1][sutun-1]==1)
			{
				cakisma=1;
			}
            if(satir>0 && sutun<8 && oyunTahtasi[satir-1][sutun+1]== 1)
			{
				cakisma=1;
			}
            if(satir<8 && sutun>0 && oyunTahtasi[satir+1][sutun-1]== 1)
			{
				cakisma=1;
			}
            if (satir<8 && sutun<8 && oyunTahtasi[satir+1][sutun+1] ==1)
			{
				cakisma=1;
			}
            if (satir>= 2 && sutun>=2 && oyunTahtasi[satir-2][sutun-2]==1)
			{
				cakisma=1;
			}
            if (satir>=2 && sutun<= 6 && oyunTahtasi[satir-2][sutun+2]==1)
			{
				cakisma=1;
			}
            if (satir<=6 && sutun>=2 && oyunTahtasi[satir+2][sutun-2]==1)
			{
				cakisma=1;
			}
            if (satir<=6 && sutun<=6 && oyunTahtasi[satir+2][sutun+2]==1)
			{
				cakisma=1;
			}

            if(cakisma==0){
                oyunTahtasi[satir][sutun]=2;
                yerlesen2++;
            }
        }
    }

    int tur=1;
    int pc_hic_yedi_mi=0;
    int k_kaynak, k_hedef; 
    int k_satir, k_sutun, h_satir, h_sutun; 

    while(1){
    	printf("   ");
    	for(j=0; j<9; j++){
    	printf("   %d", j+1);
    	}
		printf("\n");

    	for (i=0; i<9; i++) {
        printf(" %d | ", i+1);
        for (j=0; j<9; j++) {
            if(oyunTahtasi[i][j]==0){
                printf(" . |");
            }
            else
			{
                printf(" %d |", oyunTahtasi[i][j]);
			}
		}
        printf("\n");
    }
    	int gecerli_hamle=0;
        printf("\nPiyonunu sec: ");
        scanf("%d", &k_kaynak);
		k_satir=(k_kaynak-1)/9;
        k_sutun=(k_kaynak-1)%9;
        if(k_kaynak<1 || k_kaynak>81) 
		{
             printf("Gecersiz hamle!\n");
             continue;
        }
        if(oyunTahtasi[k_satir][k_sutun]!=1) 
		{
            printf("Gecersiz hamle!\n", k_kaynak);
            continue;
        }
        if(k_kaynak==-1){
			break;
    	}
    	
        printf("\nPiyon nereye gitsin? : ");
        scanf("%d" , &k_hedef);
		h_satir=(k_hedef-1)/9;
		h_sutun=(k_hedef-1)%9;
        
        if(k_kaynak==-1)
		{
		break;
		}
        k_satir=(k_kaynak-1)/9;
        k_sutun=(k_kaynak-1)%9;
        
        h_satir=(k_hedef-1)/9;
        h_sutun=(k_hedef-1)%9;
        
        int dr=h_satir-k_satir;
        int dc=h_sutun-k_sutun; 
        int abs_dr=abs(dr);       
        int abs_dc=abs(dc);
        if(dc==0)
		{
            printf("Gecersiz hamle!\n");
            continue;
        }
        if(abs_dr<=1 && abs_dc<=1){
            if(oyunTahtasi[h_satir][h_sutun]==0){
                oyunTahtasi[h_satir][h_sutun]=1;
                oyunTahtasi[k_satir][k_sutun]=0;
                gecerli_hamle=1;
                tur++;
            }
			else
			{
                printf("Gecersiz hamle!\n");
            }
        }
        else if(abs_dr==2 && abs_dc==2){
            if(oyunTahtasi[h_satir][h_sutun]==2) {
                int orta_satir=(k_satir + h_satir)/2;
                int orta_sutun=(k_sutun + h_sutun)/2;
                
                if(oyunTahtasi[orta_satir][orta_sutun]==2)
				{
                    printf("Gecersiz hamle!\n");
                } 
                else 
				{
                    oyunTahtasi[h_satir][h_sutun]=1;
                    oyunTahtasi[k_satir][k_sutun]=0;
                    tur++;
                }
            } 
			else 
			{
                printf("Gecersiz hamle!\n");
            }
        }
        else 
		{
            printf("Gecersiz hamle!\n");
        }
        if(gecerli_hamle==0){
            continue;
        }
        	if(tur>=5 && pc_hic_yedi_mi==1) 
		{
            printf("Oyun bitti..\n");
            break;
        }
        else if(tur>=5 && pc_hic_yedi_mi==0)
		{
             printf("\nOyuncu 2 tas yemedigi icin oyun devam edecek.\n");
        }
        printf("\nOyuncu 2 oynuyor!\n");
        int yeme_kaynak[100], yeme_hedef[100], yeme_sayisi = 0;
        int normal_kaynak[100], normal_hedef[100], normal_sayisi = 0;
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++){
                
                if(oyunTahtasi[i][j]==2){
                    int yeme_yon_satir[]={-2, -2, 2, 2};
                    int yeme_yon_sutun[]={-2, 2, -2, 2};
                    
                    for(int k=0; k<4; k++){
                        int hedef_satir=i+yeme_yon_satir[k]; 
                        int hedef_sutun=j+yeme_yon_sutun[k];
                        if(hedef_satir>=0 && hedef_satir<9 && hedef_sutun>=0 && hedef_sutun<9){
                            if(oyunTahtasi[hedef_satir][hedef_sutun]==1)
							{
                                int orta_satir=(i+hedef_satir)/2;
                                int orta_sutun=(j+hedef_sutun)/2;
                                if(oyunTahtasi[orta_satir][orta_sutun]!=1)
								{
                                    yeme_kaynak[yeme_sayisi]=i*9 +j;
                                    yeme_hedef[yeme_sayisi]= hedef_satir* 9 +hedef_sutun;
                                    yeme_sayisi++;
                                }
                            }
                        }
                    }
                    int normal_yon_satir[]={0, 0, -1, -1, 1, 1};
                    int normal_yon_sutun[]={-1, 1, -1, 1, -1, 1};
                    
                    for(int k=0; k<6; k++){
                        int hedef_satir=i+normal_yon_satir[k];
                        int hedef_sutun=j+normal_yon_sutun[k];
                        
                        if(hedef_satir>=0 && hedef_satir<9 && hedef_sutun>=0 && hedef_sutun<9) {
                            if(oyunTahtasi[hedef_satir][hedef_sutun]==0){
                                normal_kaynak[normal_sayisi]=i*9 +j;
                                normal_hedef[normal_sayisi] = hedef_satir*9 + hedef_sutun;
                                normal_sayisi++;
                            }
                        }
                    }
                }
            }
        }
        if (yeme_sayisi>0){
            int r=rand()%yeme_sayisi;
            int secilen_kaynak=yeme_kaynak[r];
            int secilen_hedef=yeme_hedef[r];
            int k_satir=secilen_kaynak/9;
            int k_sutun=secilen_kaynak%9;
            int h_satir=secilen_hedef/9;
            int h_sutun=secilen_hedef%9;
            
            oyunTahtasi[h_satir][h_sutun]=2;
            oyunTahtasi[k_satir][k_sutun]=0;
            
            printf("Oyuncu 2 tasinizi yedi! (%d > %d)\n", secilen_kaynak+1, secilen_hedef+1);
            pc_hic_yedi_mi=1;
            
        } 
		else if(normal_sayisi>0) 
		{
            int r=rand()%normal_sayisi;
            int secilen_kaynak=normal_kaynak[r];
            int secilen_hedef=normal_hedef[r];
            
            int k_satir=secilen_kaynak/9;
            int k_sutun=secilen_kaynak%9;
            int h_satir=secilen_hedef/9;
            int h_sutun=secilen_hedef%9;
            
            oyunTahtasi[h_satir][h_sutun]=2;
            oyunTahtasi[k_satir][k_sutun]=0;
            
            printf("Oyuncu 2'nin hamlesi : %d > %d\n", secilen_kaynak+1, secilen_hedef+1);
            
        } 
		
		if(tur>=5 && pc_hic_yedi_mi==1) 
		{
            printf("Oyun bitti..\n");
            break;
        }
        else if(tur>=5 && pc_hic_yedi_mi==0)
		{
             printf("\nOyuncu 2 tas yemedigi icin oyun devam edecek.\n");
        }

        tur++; 
    }
    printf("   ");
    for(j=0; j<9; j++)
	{
	printf("   %d", j+1);
	}
    printf("\n");

    for(i=0; i<9; i++){
        printf(" %d | ", i+1);
        for(j=0; j<9; j++){
            if(oyunTahtasi[i][j]==0)
            {
                printf(" . |");
        	}
			else
			{
                printf(" %d |", oyunTahtasi[i][j]);
  			}
		}
        printf("\n");
    }
    return 0;
}
