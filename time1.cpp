#include "time2.h"

int time1()
{
   // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(600, 450, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("0.bmp");
    SDL_Surface* linha = SDL_LoadBMP("linha.bmp");
    SDL_Surface* badbmp = SDL_LoadBMP("000.bmp");
    SDL_Surface* tardis = SDL_LoadBMP("tardis.bmp");

   SDL_Rect offset;
    offset.x = 420;
    offset.y = 316;
    int clic1, clic2, clic3, clic4, clic5, clic6, clic7, clic8, lado;
    clic1=0;
    clic2=-1;
    clic3=-1;
    clic4=-1;
    clic5=0;
    clic6=-1;
    clic7=-1;
    clic8=-1;
    SDL_Rect grama;
    grama.x = 0;
    grama.y = 350;

    SDL_Rect timespace;
    timespace.x = 20;
    timespace.y = 178;

        SDL_Rect inimigo;
    inimigo.x = 150;
    inimigo.y = 316;

    lado=0;
int reg, grav;
reg=0;
grav=0;
int vetor[10000];
vetor[0]=0;
int i,p,espelho;
i=10; //o número de i tem que ser par, e metade do valor + 1 será a diferença
p=0;
espelho=0;
    // program main loop
   bool done = false;
    while (!done)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
                    p++;
                    i++;
                    vetor[i]=0;
            switch (event.type)
            {
            case SDL_QUIT:
                done = true;
                break;

            case SDL_KEYDOWN:
                {


                    if (event.key.keysym.sym == SDLK_UP)
                    {
                    vetor[i]=vetor[i]+1;
                        if(lado<1)
                        {
                        clic2=-1;
                        clic1=-1;
                        clic3=clic3+1;
                        clic4=-1;
                        offset.y=offset.y-20;
                        }
                        if(lado>1)
                        {
                        clic1=-1;
                        clic2=-1;
                        clic4=clic4+1;
                        clic3=-1;
                        offset.y=offset.y-20;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_DOWN)
                    {
                    vetor[i]=vetor[i]+2;
                        offset.y=offset.y+0;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT)
                    {
                    vetor[i]=vetor[i]+3;
                    lado=0;
                        if(offset.y<316)
                        {
                        clic1=-1;
                        clic2=-1;
                        clic4=-1;
                        clic3=clic3+1;
                        offset.x=offset.x+10;
                        }
                        if(offset.y>=316)
                        {
                        clic4=-1;
                        clic3=-1;
                        clic2=-1;
                        clic1=clic1+1;
                        offset.x=offset.x+10;
                        }
                    }
                    if (event.key.keysym.sym == SDLK_LEFT)
                    {
                    vetor[i]=vetor[i]+4;
                    lado=2;
                        if(offset.y<316)
                        {
                        clic1=-1;
                        clic2=-1;
                        clic3=-1;
                        clic4=clic4+1;
                        offset.x=offset.x-10;
                        }
                        if(offset.y>=316)
                        {
                        clic4=-1;
                        clic3=-1;
                        clic1=-1;
                        clic2=clic2+1;
                        offset.x=offset.x-10;
                        }
                    }
                     if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        done = true;
                    }
                }

        if(vetor[p]==0)
        {
        inimigo.x=inimigo.x;
        }
        if(vetor[p]==4)
        {
        espelho=1;
        if(inimigo.y<316)
                        {
                        clic6=-1;
                        clic5=-1;
                        clic7=-1;
                        clic8=clic8+1;
                        inimigo.x=inimigo.x-10;
                        }
                        if(inimigo.y>=316)
                        {
                        clic6=clic6+1;
                        clic5=-1;
                        clic7=-1;
                        clic8=-1;
                        inimigo.x=inimigo.x-10;
                        }
        }
        if(vetor[p]==3)
        {
        espelho=2;
        if(inimigo.y<316)
                        {
                        clic6=-1;
                        clic5=-1;
                        clic8=-1;
                        clic7=clic7+1;
                        inimigo.x=inimigo.x+10;
                        }
                        if(inimigo.y>=316)
                        {
                        clic5=clic5+1;
                        clic6=-1;
                        clic7=-1;
                        clic8=-1;
                        inimigo.x=inimigo.x+10;
                        }
        }
        if(vetor[p]==1)
        {
        if(espelho==2){
        inimigo.y=inimigo.y-20;
                        clic5=-1;
                        clic6=-1;
                        clic7=clic7+1;
                        clic8=-1;
                        }
        if(espelho==1){
        inimigo.y=inimigo.y-20;
                        clic5=-1;
                        clic6=-1;
                        clic8=clic8+1;
                        clic7=-1;
             }
        }



            }
        }


        if(offset.y<316)
        {
        if(reg==15)
        {
        offset.y=offset.y+10;
        reg=0;
        }
        if(reg<15)
        {
        reg=reg+1;
        }
        }
        if(inimigo.y<316)
        {
        if(grav==15)
        {
        inimigo.y=inimigo.y+10;
        grav=0;
        }
        if(grav<15)
        {
        grav=grav+1;
        }
        }


        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255));

        // draw bitmap

        SDL_BlitSurface(linha, 0, screen, &grama);
        SDL_BlitSurface(tardis, 0, screen, &timespace);
        Uint32 colorkey = SDL_MapRGB( tardis->format, 255, 255, 255);
        SDL_SetColorKey( tardis, SDL_SRCCOLORKEY, colorkey );
if(clic1%4==0)
{
        SDL_Surface* bmp = SDL_LoadBMP("1.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic1%4==1)
{
        SDL_Surface* bmp = SDL_LoadBMP("2.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic1%4==2)
{
        SDL_Surface* bmp = SDL_LoadBMP("3.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic1%4==3)
{
        SDL_Surface* bmp = SDL_LoadBMP("4.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}

if(clic2%4==0)
{
        SDL_Surface* bmp = SDL_LoadBMP("11.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic2%4==1)
{
        SDL_Surface* bmp = SDL_LoadBMP("22.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic2%4==2)
{
        SDL_Surface* bmp = SDL_LoadBMP("33.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic2%4==3)
{
        SDL_Surface* bmp = SDL_LoadBMP("44.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic3%2==0)
{
        SDL_Surface* bmp = SDL_LoadBMP("010.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic3%2==1)
{
        SDL_Surface* bmp = SDL_LoadBMP("020.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic4%2==0)
{
        SDL_Surface* bmp = SDL_LoadBMP("110.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic4%2==1)
{
        SDL_Surface* bmp = SDL_LoadBMP("220.bmp");
            Uint32 colorkey = SDL_MapRGB( bmp->format, 255, 255, 255);
            SDL_SetColorKey( bmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(bmp, 0, screen, &offset);
}
if(clic5%4==0)
{
        SDL_Surface* badbmp = SDL_LoadBMP("000.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic5%4==1)
{
        SDL_Surface* badbmp = SDL_LoadBMP("111.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic5%4==2)
{
        SDL_Surface* badbmp = SDL_LoadBMP("222.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic5%4==3)
{
        SDL_Surface* badbmp = SDL_LoadBMP("333.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}

if(clic6%4==0)
{
        SDL_Surface* badbmp = SDL_LoadBMP("0000.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic6%4==1)
{
        SDL_Surface* badbmp = SDL_LoadBMP("1111.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic6%4==2)
{
        SDL_Surface* badbmp = SDL_LoadBMP("2222.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic6%4==3)
{
        SDL_Surface* badbmp = SDL_LoadBMP("3333.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255 );
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic7%2==0)
{
        SDL_Surface* badbmp = SDL_LoadBMP("1010.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255);
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic7%2==1)
{
        SDL_Surface* badbmp = SDL_LoadBMP("2020.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255);
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic8%2==0)
{
        SDL_Surface* badbmp = SDL_LoadBMP("1110.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255);
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}
if(clic8%2==1)
{
        SDL_Surface* badbmp = SDL_LoadBMP("2220.bmp");
            Uint32 colorkey = SDL_MapRGB( badbmp->format, 255, 255, 255);
            SDL_SetColorKey( badbmp, SDL_SRCCOLORKEY, colorkey );
        SDL_BlitSurface(badbmp, 0, screen, &inimigo);
}

        SDL_Flip(screen);
    }
    SDL_FreeSurface(bmp);
    SDL_FreeSurface(tardis);
    SDL_FreeSurface(badbmp);

    int j;
    for(j=0;j<i;j++)
    {
    printf("\n%d", vetor[j]);
    }
return 0;
}
