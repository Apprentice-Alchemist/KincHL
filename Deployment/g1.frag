 _tex_sampler  tex   DXBCQФc\(ѓькrЖи   08     8   и     @  Ќ  (  RDEF                  џџ  m   \                            i            џџџџ          _tex_sampler tex Microsoft (R) HLSL Shader Compiler 10.1 ЋЋЋISGN,                              TEXCOORD ЋЋЋOSGN,                               SV_Target ЋЋSHDRd   @      Z   `     X  p     UU  b 2     e  ђ      E  	ђ      F     F~      `     >  STATt                                                                                                                   SPDB 6  Microsoft C/C++ MSF 7.00
DS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              Рџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџ8  ќџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџџ       <       џџџџ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         .18nЁ_    .№LЁhKйпр                          мQ3                                                                                                                                                                                                                                                                                                                                                                                                                                                                    oss_Input stage_input)
{
    texCoord = stage_input.texCoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
        B                 C                                                                                                                                                                                                                                                                                                          u Ўћ h  Т ЦZ  + СУ  1ћ З P гc   С! AЙ U 1 }к                                                                                                                                                                                                                                                                                                                                                                                                                                                            Texture2D<float4> tex : register(t0);
SamplerState _tex_sampler : register(s0);

static float4 FragColor;
static float2 texCoord;

struct SPIRV_Cross_Input
{
    float2 texCoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    FragColor = tex.Sample(_tex_sampler, texCoord);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texCoord = stage_input.texCoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ўяўя   Ќ   C:\Users\horseboy\Development\Projects\KincHL\build\g1.frag.hlsl  c:\users\horseboy\development\projects\kinchl\build\g1.frag.hlsl Texture2D<float4> tex : register(t0);
SamplerState _tex_sampler : register(s0);

static float4 FragColor;
static float2 texCoord;

struct SPIRV_Cross_Input
{
    float2 texCoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    FragColor = tex.Sample(_tex_sampler, texCoord);
}

SPIRV_Cross_Output main(SPIRV_Crт0    1Ў№Бж                                                               C   (   т0їЂќ/'     B   C                                                                                                                                                                                                                                                                                                                                                                                                                  B <   
  "aJ
  "aJMicrosoft (R) HLSL Shader Compiler 10.1   6 =hlslFlags 0x1 hlslTarget ps_4_0 hlslEntry main     *     и      (       (     <     main 2 >  	 stage_input                                P     <    (      P    <    (    : >   <main return value>                                P     <    (      P    <    (     P    <    (     P    <    (    & M   д      	3 $ 	2<$     N  є         к2ИВ9GCдШ  ђ   H         d          <   <     <      `     `              і                              ,                                                                                                                                                                                                                                                                                                                                                                                                               Ъ18        H  
 џџ   џџ     D   D      L        @       float2 ѓђё       texCoord ё&               SPIRV_Cross_Input 
       @       float4 ѓђё      FragColor *               SPIRV_Cross_Output ѓђё
            
       	           а)  ђё
     
          
а)  ђё
     
                                                                                                                                     )K                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             Ъ18            џџ   џџ                          
  frag_main ђё                                                                                                                                                                                                                                                                                                                                                                                                                                                D3DSHDR d                              `                  
  frag_main ђё                                                                                                                                                                                                                                                                                                                                                                                                                                                џџџџ	/ё     -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       %        main   Q   џџџџ  џџџџtex " Q   џџџџџџ  џџ_tex_sampler                                                                                                                                                                                                                                                                                                                                                                                                                                                                               џџџџ	/ё                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            .18nЁ_    .№LЁhKйпрn   /LinkInfo /names /src/headerblock /src/files/c:\users\horseboy\development\projects\kinchl\build\g1.frag.hlsl          :             
             "          мQ3                                                                                                                                                                                                                                                                                                                      џџџџw	1      ?\   L       ,   P                                    d      `             	 м                        main none   -К.ё       d      `                    џџџџ    d         џџџџ    џџџџ         C:\Users\horseboy\Development\Projects\KincHL\build\g1.frag.hlsl    ўяўя                  џџџџџџџџџџ џџџџџџџџџџ                                                                                                                                                                                Ъ     W  P       м     '  t  L      (   8  ,   P                  
            	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             