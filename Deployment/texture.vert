pos  tex $Globals  mvp     ,   DXBC‘е}Јљ?јEx?К¬"В   d9     8   ф   @  Ш  а  \  RDEFі      H          ю€  М   <                              $Globals ЂЂЂ<      `   0           x       ,      |       mvp             Microsoft (R) HLSL Shader Compiler 10.1 ISGND         8                    8                  TEXCOORD ЂЂЂOSGNP         8                    A                   TEXCOORD SV_Position ЂЂЂSHDR@  @  P   Y  FО         _  2     _  2    e  2      g  т        h     6  2      F    6  В     @    А?6  2      F     6  B      @     ?  В      F     FВ            В      :      @    А?8  B     :      @     ?       F     FВ            "     F     FВ         >  STATt   
                                                                                                              SPDB 6  Microsoft C/C++ MSF 7.00
DS            Ф                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ј€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€8  ш€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€       <       €€€€                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         Ф.1П"†_   -a В∞|MЊґ“°к\@                          №Q3                                                                                                                                                                                                                                                                                                                                                                                                                                                                    pos.x, pos.y, 0.5f), mvp), 1.0f);
    texcoord = tex;
    gl_Position.z = (gl_Position.z + gl_Position.w) * 0.5;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    pos = stage_input.pos;
    tex = stage_input.tex;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.texcoord = texcoord;
    return stage_output;
}
        G      H       О                                                                                               Lи uГ г  h  &ч ∆Z  >  Ѕ√  ў* ,  PЕ & ЛЉ Z  ±≈                                                                                                                                                                                                                                                                                                                                                                                                                                                                     uniform float3x3 mvp;

static float4 gl_Position;
static float3 pos;
static float2 texcoord;
static float2 tex;

struct SPIRV_Cross_Input
{
    float3 pos : TEXCOORD0;
    float2 tex : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float2 texcoord : TEXCOORD0;
    float4 gl_Position : SV_Position;
};

void vert_main()
{
    gl_Position = float4(mul(float3(pos.x, pos.y, 0.5f), mvp), 1.0f);
    texcoord = tex;
    gl_Position.z = (gl_Position.z + gl_Position.w) * 0.5;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    pos = stage_input.pos;
    tex = stage_input.tex;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.texcoord = texcoord;
    return stage_output;
}
                                                                                                                                                                                                                                                                                    юпюп   {   C:\Users\horseboy\Development\Projects\KincHL\build\texture.vert.hlsl  c:\users\horseboy\development\projects\kinchl\build\texture.vert.hlsl uniform float3x3 mvp;

static float4 gl_Position;
static float3 pos;
static float2 texcoord;
static float2 tex;

struct SPIRV_Cross_Input
{
    float3 pos : TEXCOORD0;
    float2 tex : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float2 texcoord : TEXCOORD0;
    float4 gl_Position : SV_Position;
};

void vert_main()
{
    gl_Position = float4(mul(float3(в0А   Ю~Ёю*±÷                                                               H   (   в0CЂBXм     G   H                                                                                                                                                                                                                                                                                                                                                                                                                  B <   
  "aJ
  "aJMicrosoft (R) HLSL Shader Compiler 10.1   6 =hlslFlags 0x1 hlslTarget vs_4_0 hlslEntry main     *           м       м   	  T    †main 2 >  	 stage_input                                P     T    м      P    T    м     P    T    м     P    T    м     P    T    м    : >  И <main return value>                                P    T    м     P    T    м     P    T    м     P    T    м     P     T    м      P    T    м    2 >   gl_Position                                P     ƒ        F MА         	E(:HE@8 	=| 	2H	9	=@2 >   gl_Position                                P     ƒ         N   R       €€€€€€gl_Position ф         г«ПЄНGґ£РЭ–«“Qэ  т           @         ь   T   #  АT   #   h   #  Аh   #   |     А|      Р     АР      §     А§      ƒ     Аƒ      а     Аа      ь     Аь          А     <  #  А<  #                                           ц                              ,                                                                                                                                                                                                                                                                                                                                                                                                18        l  
 €€   €€     <   <      D        @       float3 утс @       float2 утс"       pos тс    tex тс&               SPIRV_Cross_Input 
       @       float4 утс.      texcoord с    gl_Position тс*               SPIRV_Cross_Output утс
            
       
         @             , float3x3 
     
                                                                                                 })                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             18            €€   €€                            vert_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                D3DSHDR @                             `                    vert_main тс                                                                                                                                                                                                                                                                                                                                                                                                                                                €€€€	/с                 -                                                                        А                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   %    А    main   Q       €€€€€€mvp  R       €€€€€€gl_Position                                                                                                                                                                                                                                                                                                                                                                                                                                                                                €€€€	/с                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            Ф.1П"†_   -a В∞|MЊґ“°к\@s   /LinkInfo /names /src/headerblock /src/files/c:\users\horseboy\development\projects\kinchl\build\texture.vert.hlsl                 "            
                 №Q3                                                                                                                                                                                                                                                                                                                 €€€€w	1     О ?\   L       ,   T                                    @     `             	 ,      H                 main none   -Ї.с       @     `                    €€€€    @        €€€€    €€€€         C:\Users\horseboy\Development\Projects\KincHL\build\texture.vert.hlsl   юпюп                  €€€€€€€€€€ €€€€€€€€€€                                                                                                                                                                            ѕ   §  [  P       Ђ  А   м  Д  D      (   8  ,   L                  
            	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            