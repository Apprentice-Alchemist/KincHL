 _texsampler_sampler  texsampler   DXBC)ЄЮЄ©ѓМ9еµTЂT   И8     8   д     L    А  RDEF§                  €€  {   \                            p            €€€€          _texsampler_sampler texsampler Microsoft (R) HLSL Shader Compiler 10.1 ЂISGN,                              TEXCOORD ЂЂЂOSGN,                               SV_Target ЂЂSHDR∞   @   ,   Z   `     X  p     UU  b 2     e  т      h     6  В      @    А?E  	т      F     F~      `              
      @     ?6  b      V     >  STATt                                                                                                                SPDB 6  Microsoft C/C++ MSF 7.00
DS            Р                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ј€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€8  ь€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€       <       €€€€                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Ф.18n°_   mКI≈^€IІ9ѕ±4§¶                          №Q3                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ord);
    FragColor = float4(color.x + 0.5f, color.y, color.z, 1.0f);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texcoord = stage_input.texcoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
    О   G       H                                                                                                                                                                                                            uГ A h  ¬ ∆Z  + Ѕ√  1ы КЈ PЕ ”c  ЩП Ѕ! Aє UШ Х1 }Џ                                                                                                                                                                                                                                                                                                                                                                                                                                                            Texture2D<float4> texsampler : register(t0);
SamplerState _texsampler_sampler : register(s0);

static float2 texcoord;
static float4 FragColor;

struct SPIRV_Cross_Input
{
    float2 texcoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    float4 color = texsampler.Sample(_texsampler_sampler, texcoord);
    FragColor = float4(color.x + 0.5f, color.y, color.z, 1.0f);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texcoord = stage_input.texcoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.FragColor = FragColor;
    return stage_output;
}
                                                                                                                                                                                                                                                                                                                                                                                          юпюп      C:\Users\horseboy\Development\Projects\KincHL\build\texture.frag.hlsl  c:\users\horseboy\development\projects\kinchl\build\texture.frag.hlsl Texture2D<float4> texsampler : register(t0);
SamplerState _texsampler_sampler : register(s0);

static float2 texcoord;
static float4 FragColor;

struct SPIRV_Cross_Input
{
    float2 texcoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 FragColor : SV_Target0;
};

void frag_main()
{
    float4 color = texsampler.Sample(_texsampler_sampler, texcoв0А   ьлы≠р±÷                                                               H   (   в0ЁP•ЃЖ     G   H                                                                                                                                                                                                                                                                                                                                                                                                                  B <   
  "aJ
  "aJMicrosoft (R) HLSL Shader Compiler 10.1   6 =hlslFlags 0x1 hlslTarget ps_4_0 hlslEntry main     *     \      l       l     D    †main 2 >  	 stage_input                                P     D    l      P    D    l    : >  И <main return value>                                P     D    l      P    D    l     P    D    l     P    D    l    2 MА   X      	D?$ 	CX0	%$. >   color                                  P      |    0      P     |    0     P     |    0     N  ф         ФЃ=РтфyзftОC`c  т   Р         ∞       
   Д   D     АD      X     АX      |     А|      Ш     АШ      ђ     Ађ                          ц                              4                                                                                                                                                                                                    18        H  
 €€   €€     D   D      L        @       float2 утс       texcoord с&               SPIRV_Cross_Input 
       @       float4 утс      FragColor *               SPIRV_Cross_Output утс
            
       	           –)  тс
     
          
–)  тс
     
                                                                                                                                     )K                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              18            €€   €€                          
  frag_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                D3DSHDR ∞                              `                  
  frag_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                €€€€	/с                 5                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           %    А    main   Q   €€€€  €€€€texsampler  & Q   €€€€€€  €€_texsampler_sampler                                                                                                                                                                                                                                                                                                                                                                                                                                                                €€€€	/с                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            Ф.18n°_   mКI≈^€IІ9ѕ±4§¶s   /LinkInfo /names /src/headerblock /src/files/c:\users\horseboy\development\projects\kinchl\build\texture.frag.hlsl          :             
             "          №Q3                                                                                                                                                                                                                                                                                                                 €€€€w	1     О ?\   L       ,   T                                    ∞      `             	 `      –                  main none   -Ї.с       ∞      `                    €€€€    ∞         €€€€    €€€€         C:\Users\horseboy\Development\Projects\KincHL\build\texture.frag.hlsl   юпюп                  €€€€€€€€€€ €€€€€€€€€€                                                                                                                                                                            ѕ   А  [  P       E  А   Ж  @  L      (   8  ,   \                  
            	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             