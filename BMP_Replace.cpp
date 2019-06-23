#include "qdbmp.h"

int main()
{
	BMP *Original_pic, *Background , *Replace ;
	char fOriginal[20] , fBackground[20] , fReplace[20] , fOutput[20];
	
	printf("Enter original File name : ");
	scanf("%s",fOriginal);
	printf("Enter background File name : ");
	scanf("%s",fBackground);
	printf("Enter Replace File name : ");
	scanf("%s",fReplace);
	printf("Enter Output File name : ");
	scanf("%s",fOutput);
	
	UCHAR	r1, g1, b1,r2,g2,b2,r3,g3,b3;
	UINT	width, height,width2,height2,width3,height3;
	UINT	x,y;
	Original_pic = BMP_ReadFile(fOriginal);
	Background = BMP_ReadFile(fBackground);
	Replace = BMP_ReadFile(fReplace);
	
	width = BMP_GetWidth(Original_pic);
	height = BMP_GetHeight(Original_pic);
	
	width2 = BMP_GetWidth(Background);
	height2 = BMP_GetHeight(Background);
	
	width3 = BMP_GetWidth(Replace);
	height3 = BMP_GetHeight(Replace);
	
	if(width != width2 || width != width3 || width2 != width3)
	{
		printf("\nAll Three pictures should be of same Dimensions\nTry Again *_*");
		return 0;
	}
	
	for(x = 0;x < width; x++)
	{
		for(y = 0;y < height; y++)
		{
			BMP_GetPixelRGB(Original_pic, x, y , &r1,&b1,&g1);
			BMP_GetPixelRGB(Background, x, y , &r2,&b2,&g2);
			BMP_GetPixelRGB(Replace, x, y , &r3,&b3,&g3);
			
			if(r1 == r2 && b1 == b2 && g1 == g2)
			{
				BMP_SetPixelRGB(Original_pic,x,y,r3,b3,g3);
			}
		}
	}
	
	BMP_WriteFile(Original_pic,fOutput);
	BMP_Free(Original_pic);
	BMP_Free(Replace);
	BMP_Free(Background);
	
	return 0;
}
