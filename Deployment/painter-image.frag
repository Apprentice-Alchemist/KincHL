 _tex_sampler  tex   DXBC!ФveИАhЌ@NG.с   ®8     8   Ў   $  X  $  †  RDEFШ                  €€  m   \                            i            €€€€          _tex_sampler tex Microsoft (R) HLSL Shader Compiler 10.1 ЂЂЂISGND         8                    8                  TEXCOORD ЂЂЂOSGN,                               SV_Target ЂЂSHDRƒ   @   1   Z   `     X  p     UU  b т     b 2    e  т      h     E  	т      F    F~      `     8  т      F     F     8  r      F     ц     6  В      :      >  STATt                                                                                                                SPDB 6  Microsoft C/C++ MSF 7.00
DS            Р                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ј€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€8  ь€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€       <       €€€€                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Ф.1n$°_   НН(bK/БKТ•Юu{С5                          №Q3                                                                                                                                                                                                                                                                                                                                                                                                                                                                    color = tex.Sample(_tex_sampler, texCoord) * color;
    float3 _32 = texcolor.xyz * color.w;
    texcolor = float4(_32.x, _32.y, _32.z, texcolor.w);
    FragColor = texcolor;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texCoord = stage_input.texCoord;
    color = stage_input.color;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
    Ъ   M                  N                                                         ∆Z  uГ £Ј h  &ч }Ь Ѕ√  1ы ®—  PЕ ”c  ї  Ѕ! Aє UШ Х1 }Џ                                                                                                                                                                                                                                                                                                                                                                                                                                                            Texture2D<float4> tex : register(t0);
SamplerState _tex_sampler : register(s0);

static float2 texCoord;
static float4 color;
static float4 FragColor;

struct SPIRV_Cross_Input
{
    float4 color : TEXCOORD0;
    float2 texCoord : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    float4 texcolor = tex.Sample(_tex_sampler, texCoord) * color;
    float3 _32 = texcolor.xyz * color.w;
    texcolor = float4(_32.x, _32.y, _32.z, texcolor.w);
    FragColor = texcolor;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texCoord = stage_input.texCoord;
    color = stage_input.color;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
                                                                                                                                                                                                                                                              юпюп   Э   C:\Users\horseboy\Development\Projects\KincHL\build\painter-image.frag.hlsl  c:\users\horseboy\development\projects\kinchl\build\painter-image.frag.hlsl Texture2D<float4> tex : register(t0);
SamplerState _tex_sampler : register(s0);

static float2 texCoord;
static float4 color;
static float4 FragColor;

struct SPIRV_Cross_Input
{
    float4 color : TEXCOORD0;
    float2 texCoord : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    float4 texв0А   яБ‘≤ƒ±÷                                                               N   (   в0‘Ф£«     M   N                                                                                                                                                                                                                                                                                                                                                                                                                  B <   
  "aJ
  "aJMicrosoft (R) HLSL Shader Compiler 10.1   6 =hlslFlags 0x1 hlslTarget ps_4_0 hlslEntry main     *     Ў      t       t     P    †main 2 >  	 stage_input                                P     P    t      P    P    t     P    P    t     P    P    t     P    P    t     P    P    t    : >  И <main return value>                                P     P    t      P    P    t     P    P    t     P    P    t    6 MА   ‘      	A (@ 	8P0@$	'  . >    texcolor                               P      Р    0      P     Р    0     P     Р    0     P     Р    0     N  ф         mЙtХы0»Dиd[yA ^  т   Р         ƒ       
   Д   P     АP      t     Аt      Р     АР      ђ   "  Ађ   "   ј   "  Ај   "                       ц                              ,                                                                        18        X  
 €€   €€     D   D      L        @       float4 утс @       float2 утс&       color     texCoord с&               SPIRV_Cross_Input 
             FragColor *               SPIRV_Cross_Output утс
            
       	            –)  тс
     
          
–)  тс
     
                                                                                                                     )K                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              18            €€   €€                          
  frag_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                D3DSHDR ƒ                              `                  
  frag_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                €€€€	/с     -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       %    А    main   Q   €€€€  €€€€tex " Q   €€€€€€  €€_tex_sampler                                                                                                                                                                                                                                                                                                                                                                                                                                                                               €€€€	/с                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            Ф.1n$°_   НН(bK/БKТ•Юu{С5y   /LinkInfo /names /src/headerblock /src/files/c:\users\horseboy\development\projects\kinchl\build\painter-image.frag.hlsl          :             
             "          №Q3                                                                                                                                                                                                                                                                                                           €€€€w	1     О ?\   L       ,   X                                    ƒ      `             	 №      –                  main none   -Ї.с       ƒ      `                    €€€€    ƒ         €€€€    €€€€         C:\Users\horseboy\Development\Projects\KincHL\build\painter-image.frag.hlsl юпюп                  €€€€€€€€€€ €€€€€€€€€€                                                                                                                                                                        ’   Р  _  P       Ќ  А     Љ  L      (   8  ,   P                  
            	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             