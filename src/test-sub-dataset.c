/**
 * RSA implementation and attack on Mbed
 * Data set used to test bgi_sub function in bigint library
 * Generated at compilation the 2014-10-22 15:09:37.741999
 * @author Cyrille Toulet, <cyrille.toulet@gmail.com>
 * @author Benjamin Burnouf, <benjamin76360@gmail.com>
 **/

#include "bigint.h"

#define TEST_SUB_COUNT 10u

mbed_int test_sub_dataset[TEST_SUB_COUNT][3][BIGINT_SIZE + 1] = {
	{
		{0x211d81feu, 0xbcaa36d8u, 0xb83ae647u, 0x4d7ee0b2u, 0x7e5f084fu, 0xbb0c8e47u, 0xc0ce92b7u, 0x0ce6d039u, 0x347ed3bbu, 0x4ea9ae86u, 0x5a46f5eeu, 0x3966fd93u, 0xa7a4c250u, 0x69fae815u, 0x6f57f7bbu, 0x415c6f58u, 0x6aedb0a3u, 0x12b8b1f7u, 0xaafa8c44u, 0x5bc53c36u, 0xd3b610f7u, 0x41b92b68u, 0x321b7d18u, 0x41bd675fu, 0x029150e0u, 0xfd7dc575u, 0x4e15f749u, 0xd2fa5320u, 0x8cf4e8bbu, 0x5f42dc8au, 0x692127aau, 0x95ee30e2u, 0x00000000u}, 
		{0xd12f5fdau, 0x17a68c48u, 0x10755461u, 0xdd1b5322u, 0x09a12cc6u, 0xd406cf87u, 0x60305582u, 0x22bcf90du, 0xd85343edu, 0xede2e5aeu, 0xa1e5df40u, 0xb42bc4d3u, 0x4994cf27u, 0x1b67b085u, 0x19cd395du, 0xfb8002cfu, 0x0b3e7961u, 0xa771c2b0u, 0x72d9d258u, 0xc715bbbbu, 0x6be731dfu, 0x7e9192d4u, 0x7db30626u, 0x631c30a6u, 0x3e2224aau, 0x7071868cu, 0x9a774e46u, 0xf63ea149u, 0xc3ba608bu, 0xbf8668e1u, 0xe165bd85u, 0x08c3270du, 0x00000000u}, 
		{0x4fee2224u, 0xa503aa8fu, 0xa7c591e6u, 0x70638d90u, 0x74bddb88u, 0xe705bec0u, 0x609e3d34u, 0xea29d72cu, 0x5c2b8fcdu, 0x60c6c8d7u, 0xb86116adu, 0x853b38bfu, 0x5e0ff328u, 0x4e933790u, 0x558abe5eu, 0x45dc6c89u, 0x5faf3741u, 0x6b46ef47u, 0x3820b9ebu, 0x94af807bu, 0x67cedf17u, 0xc3279894u, 0xb46876f1u, 0xdea136b8u, 0xc46f2c35u, 0x8d0c3ee8u, 0xb39ea903u, 0xdcbbb1d6u, 0xc93a882fu, 0x9fbc73a8u, 0x87bb6a24u, 0x8d2b09d4u, 0x00000000u}
	},
	{
		{0xcbe43149u, 0xec8b9e3du, 0x12691ad3u, 0x91940cacu, 0xfccd19d9u, 0x2c2177a8u, 0xe2852cf2u, 0x4ebad791u, 0xf0ae09feu, 0xce4618beu, 0xd3b81db3u, 0x3d27eafdu, 0x64434f94u, 0x5507848au, 0x029bd296u, 0xede6058eu, 0xd2c6b318u, 0xcd71b508u, 0x1e67111au, 0xc7f743f7u, 0x803b1ca5u, 0x244cfe8cu, 0x6bcebdd6u, 0x07f639deu, 0x73478814u, 0xccf51050u, 0x87c8a703u, 0x1f2aa809u, 0xe2c373e4u, 0x807b53c5u, 0x64c2b179u, 0xd839874cu, 0x00000000u}, 
		{0xd72423cfu, 0x37eda2b7u, 0x32004d15u, 0xbd7f9b2cu, 0x25267e06u, 0xdca2d0a7u, 0xa76e6ec6u, 0xf98a7b65u, 0xbe23c357u, 0xac60c9b9u, 0x022af40bu, 0xee0e1337u, 0xa0d715c5u, 0xbf408411u, 0x16bacedcu, 0x6cdc0250u, 0xf205b3ffu, 0xb9132f64u, 0x16ed762du, 0xbcd3e472u, 0xcf29ca6fu, 0xfcb59c6cu, 0x6fad60d2u, 0x08258501u, 0x58f21bf9u, 0x18789ab4u, 0xd118feeeu, 0x4034e291u, 0x739ecb4cu, 0x730d7dadu, 0x06990715u, 0xd1390f3fu, 0x00000000u}, 
		{0xf4c00d7au, 0xb49dfb85u, 0xe068cdbeu, 0xd414717fu, 0xd7a69bd2u, 0x4f7ea701u, 0x3b16be2bu, 0x55305c2cu, 0x328a46a6u, 0x21e54f05u, 0xd18d29a8u, 0x4f19d7c6u, 0xc36c39ceu, 0x95c70078u, 0xebe103b9u, 0x810a033du, 0xe0c0ff19u, 0x145e85a3u, 0x07799aedu, 0x0b235f85u, 0xb1115236u, 0x2797621fu, 0xfc215d03u, 0xffd0b4dcu, 0x1a556c1au, 0xb47c759cu, 0xb6afa815u, 0xdef5c577u, 0x6f24a897u, 0x0d6dd618u, 0x5e29aa64u, 0x0700780du, 0x00000000u}
	},
	{
		{0xa1846743u, 0x257deac4u, 0xc1fc00f7u, 0x8dd42b0eu, 0xc9a4c686u, 0x57a7727bu, 0x0db177f0u, 0x8e4b5a2fu, 0x199c699du, 0x4b4375ebu, 0xb9cd4893u, 0x7544c0c5u, 0x54ddb6bcu, 0xb7ecbcadu, 0x51e1b159u, 0xda73e7b7u, 0x308c977cu, 0xf3c47d03u, 0xa249b6f9u, 0xa96e76f3u, 0x2a7005acu, 0x3f211be0u, 0x1b04cc66u, 0x71f7b5e4u, 0x4c7dcc3cu, 0x8954d981u, 0xf57ce62du, 0xaa1a8fd2u, 0x81ffaa49u, 0x349aff73u, 0x28fe839eu, 0xbb686265u, 0x00000000u}, 
		{0x36521fe9u, 0xc227685eu, 0xcd8ece25u, 0x1059cc40u, 0xe0622eedu, 0x0e25b144u, 0x3fe94ff5u, 0x9905db66u, 0xe68e576du, 0xd91a1ab0u, 0x0e5d4802u, 0x29561362u, 0x4aff9d99u, 0xbfcd2220u, 0x33d4b9c1u, 0xb5cbe00au, 0x219692c6u, 0x7e03333cu, 0xf9bcf6d2u, 0xccdc0da4u, 0x2fefe8d5u, 0xfafa5d95u, 0xb01a2fb1u, 0x2db5c587u, 0xa51b048fu, 0xe0e5cfd1u, 0xb067b52fu, 0x7f568487u, 0x68d28cd2u, 0x7800560au, 0xc2f0f955u, 0x2f3a1e5eu, 0x00000000u}, 
		{0x6b32475au, 0x63568266u, 0xf46d32d1u, 0x7d7a5ecdu, 0xe9429799u, 0x4981c136u, 0xcdc827fbu, 0xf5457ec8u, 0x330e122fu, 0x72295b3au, 0xab700090u, 0x4beead63u, 0x09de1923u, 0xf81f9a8du, 0x1e0cf797u, 0x24a807adu, 0x0ef604b6u, 0x75c149c7u, 0xa88cc027u, 0xdc92694eu, 0xfa801cd6u, 0x4426be4au, 0x6aea9cb4u, 0x4441f05cu, 0xa762c7adu, 0xa86f09afu, 0x451530fdu, 0x2ac40b4bu, 0x192d1d77u, 0xbc9aa969u, 0x660d8a48u, 0x8c2e4406u, 0x00000000u}
	},
	{
		{0xde65343du, 0xedf4d711u, 0x06cbf5f5u, 0xbd813539u, 0x8b85713eu, 0xed46014eu, 0x95a76074u, 0x4ca369adu, 0xec79c24bu, 0x1fc7eb26u, 0xac465760u, 0xb02f2d03u, 0x57ceda9fu, 0xac58fa7bu, 0x6095c2bcu, 0x9c91f043u, 0xdf12c33du, 0x91d3e404u, 0xac1437dau, 0x3ce7e32eu, 0x25ded247u, 0xae42affdu, 0x23caf677u, 0xb43bcc23u, 0x90b0e590u, 0x1aac1f97u, 0x7aa1ce52u, 0x324d2924u, 0xddd057bcu, 0x59a48b0au, 0xdf65a67au, 0x86000070u, 0x00000000u}, 
		{0xbf42e1b3u, 0x4619dbb5u, 0x582950abu, 0xdc13f512u, 0xf525dadbu, 0xf3c30048u, 0xd8c0c0b9u, 0x83d30a22u, 0xd58f62d2u, 0xc895f87bu, 0x4b3bad9fu, 0xefbbaca2u, 0x1d571eadu, 0xd249671fu, 0xb907d84cu, 0x96fa225au, 0xfa3bd10au, 0x204b79cau, 0x4a273617u, 0x4eca2e7fu, 0x84fc7caeu, 0x19b013dau, 0xeab01f40u, 0xf98aad0eu, 0x23b6f77fu, 0xedf18819u, 0xe74332a4u, 0x149bda06u, 0x7869a71au, 0x71eb3ee2u, 0x516a3ac4u, 0x48ab3b89u, 0x00000000u}, 
		{0x1f22528au, 0xa7dafb5cu, 0xaea2a54au, 0xe16d4026u, 0x965f9662u, 0xf9830105u, 0xbce69fbau, 0xc8d05f8au, 0x16ea5f78u, 0x5731f2abu, 0x610aa9c0u, 0xc0738061u, 0x3a77bbf1u, 0xda0f935cu, 0xa78dea6fu, 0x0597cde8u, 0xe4d6f233u, 0x71886a39u, 0x61ed01c3u, 0xee1db4afu, 0xa0e25598u, 0x94929c22u, 0x391ad737u, 0xbab11f14u, 0x6cf9ee10u, 0x2cba977eu, 0x935e9badu, 0x1db14f1du, 0x6566b0a2u, 0xe7b94c28u, 0x8dfb6bb5u, 0x3d54c4e7u, 0x00000000u}
	},
	{
		{0xeced2e60u, 0x713eef1eu, 0x9e1612a5u, 0x23388b74u, 0x186f2335u, 0x4dcb658cu, 0x8b2aab3au, 0x5e4aa49fu, 0x8d899b37u, 0xe3798a4bu, 0xea550fdfu, 0x2eb65645u, 0xe6fef94au, 0xe2e6faf1u, 0xcb90f669u, 0x87180bcfu, 0x5dbc6239u, 0xdcaa47e8u, 0x02db455au, 0x275f21f1u, 0x49bed6eeu, 0xe3159d63u, 0x85d05c12u, 0x72f3de94u, 0x610a437bu, 0xea585a7fu, 0xeaa67438u, 0xb5e6e4f1u, 0x95ea871fu, 0xa05333beu, 0x949f15f4u, 0xbcc179acu, 0x00000000u}, 
		{0x8bbc0b83u, 0x6c7390bau, 0xf71b637cu, 0x2a6451d2u, 0x06039f54u, 0x5c7c5464u, 0x8536fa9eu, 0x27a508afu, 0x8468a8afu, 0x51ee0aebu, 0x4c11da4cu, 0xf7f2ae34u, 0x9ecd8483u, 0xc8a6ca94u, 0x23c35bbeu, 0x9fbb4e89u, 0xa0e549d5u, 0x338a9daau, 0xb605b234u, 0x38feb60du, 0x6df0e744u, 0xf7905e59u, 0xb4c29370u, 0x6ad361bdu, 0x1dec41c1u, 0x059cafb8u, 0xc8cc000cu, 0x367aafb6u, 0x1d872fd6u, 0x477a4fafu, 0x4e578f80u, 0x8074803eu, 0x00000000u}, 
		{0x613122ddu, 0x04cb5e64u, 0xa6faaf29u, 0xf8d439a1u, 0x126b83e0u, 0xf14f1128u, 0x05f3b09bu, 0x36a59bf0u, 0x0920f288u, 0x918b7f60u, 0x9e433593u, 0x36c3a811u, 0x483174c6u, 0x1a40305du, 0xa7cd9aabu, 0xe75cbd46u, 0xbcd71863u, 0xa91faa3du, 0x4cd59326u, 0xee606be3u, 0xdbcdefa9u, 0xeb853f09u, 0xd10dc8a1u, 0x08207cd6u, 0x431e01bau, 0xe4bbaac7u, 0x21da742cu, 0x7f6c353bu, 0x78635749u, 0x58d8e40fu, 0x46478674u, 0x3c4cf96eu, 0x00000000u}
	},
	{
		{0xb820225cu, 0x8febc93fu, 0x714b5590u, 0xc067eb0eu, 0xedf83e2eu, 0xe0dda16au, 0x6ed1f00eu, 0xec196d02u, 0x54acaebeu, 0x2fdb700du, 0x745a352eu, 0xa7e4158bu, 0x3fb6c411u, 0x16510898u, 0x5cdbb5e2u, 0xdf93bfd5u, 0x76d95d0bu, 0x2cf98d81u, 0xa6ee4d50u, 0x71fbd828u, 0x5cf79fa6u, 0xf9eeceeeu, 0x87453f06u, 0xd8987443u, 0xe07306ebu, 0xd7aeb548u, 0xe3e8b11bu, 0x5bfc4b19u, 0xce174e1fu, 0xc1fcdaddu, 0xc1d7239fu, 0x60913ef2u, 0x00000000u}, 
		{0xcc1cb872u, 0xc01b04f4u, 0x50da0d6du, 0x9c5ee703u, 0x4006e957u, 0x9b357accu, 0x40240ddbu, 0x1966b6dbu, 0x947e2905u, 0x1b0fda2bu, 0x4d6ea54au, 0x1eef5453u, 0xbe6d4b00u, 0xd43e554fu, 0x44a16480u, 0x3f4edaaeu, 0xb85bc21bu, 0x48dc2954u, 0x1e4a7f5fu, 0x99adc118u, 0x4cc97904u, 0xeb8c0527u, 0x1fa7d5acu, 0x638993ffu, 0x3bee6f29u, 0x335ea4cdu, 0xeefe10c0u, 0xb63babdeu, 0x457cb1c4u, 0x4de9c885u, 0x3bf2bf9du, 0x50a3dbdau, 0x00000000u}, 
		{0xec0369eau, 0xcfd0c44au, 0x20714822u, 0x2409040bu, 0xadf154d7u, 0x45a8269eu, 0x2eade233u, 0xd2b2b627u, 0xc02e85b9u, 0x14cb95e1u, 0x26eb8fe4u, 0x88f4c138u, 0x81497911u, 0x4212b348u, 0x183a5161u, 0xa044e527u, 0xbe7d9af0u, 0xe41d642cu, 0x88a3cdf0u, 0xd84e1710u, 0x102e26a1u, 0x0e62c9c7u, 0x679d695au, 0x750ee044u, 0xa48497c2u, 0xa450107bu, 0xf4eaa05bu, 0xa5c09f3au, 0x889a9c5au, 0x74131258u, 0x85e46402u, 0x0fed6318u, 0x00000000u}
	},
	{
		{0xec3b5b3bu, 0x04ea5a3fu, 0xf1ac404bu, 0x128efa1eu, 0x54f6e60au, 0x0d203807u, 0xfa4af5a4u, 0x2bf2482eu, 0x28bb6871u, 0x0036b2acu, 0xb81d693eu, 0x046c36ecu, 0x9b1f4554u, 0xc5d20e4cu, 0xfc496e7du, 0x986dfea7u, 0xe5826871u, 0xfb3b46dfu, 0x64a5cc33u, 0x605944f7u, 0x2b6dc57eu, 0x25bad71fu, 0xd1606b1eu, 0x50a31a1bu, 0xff20b32au, 0x8a06dc03u, 0x7fda4094u, 0x16f922abu, 0x70227b82u, 0x0a0f6c18u, 0xc8cc5fe9u, 0xfd723d6cu, 0x00000000u}, 
		{0x245d0b2cu, 0x442a8ac0u, 0x65d2b47cu, 0x4293c7f2u, 0x8c584120u, 0xfdb88bdeu, 0x398a6b2bu, 0x0c33e562u, 0x3cc8b57au, 0xd8c65640u, 0x1ee00daeu, 0xad50324cu, 0x660782e7u, 0xedd307fau, 0xb3f1b8f5u, 0xdb661349u, 0x4463389du, 0x16392d41u, 0x4b375545u, 0xe4432982u, 0xabe51773u, 0xf18473f5u, 0x820f562eu, 0x5dde7075u, 0x65fc65e3u, 0x4972d50bu, 0xfe48d700u, 0xf5ba1cb6u, 0x96650f85u, 0x67673a36u, 0x84ae2c2bu, 0xc8260939u, 0x00000000u}, 
		{0xc7de500fu, 0xc0bfcf7fu, 0x8bd98bceu, 0xcffb322cu, 0xc89ea4e9u, 0x0f67ac28u, 0xc0c08a78u, 0x1fbe62ccu, 0xebf2b2f7u, 0x27705c6bu, 0x993d5b8fu, 0x571c04a0u, 0x3517c26cu, 0xd7ff0652u, 0x4857b587u, 0xbd07eb5eu, 0xa11f2fd3u, 0xe502199eu, 0x196e76eeu, 0x7c161b75u, 0x7f88ae0au, 0x34366329u, 0x4f5114efu, 0xf2c4a9a6u, 0x99244d46u, 0x409406f8u, 0x81916994u, 0x213f05f4u, 0xd9bd6bfcu, 0xa2a831e1u, 0x441e33bdu, 0x354c3433u, 0x00000000u}
	},
	{
		{0x644cd8a8u, 0xf71d059fu, 0xe309236cu, 0x907bb6e5u, 0xd8675a0au, 0x7d2a26ccu, 0x59064281u, 0x266a1f60u, 0x97c28a47u, 0x916f87abu, 0x2f449debu, 0xe57a5351u, 0xb3b53f8du, 0x1f408994u, 0x59f1be37u, 0xfe4d45eau, 0x6f8120a2u, 0xf98c398cu, 0x6b6be6ddu, 0xc36ba2bau, 0x1dc3b8d9u, 0xcc90779cu, 0xadf8d6ddu, 0x56047ddcu, 0x1c8880deu, 0xdbd3a82fu, 0xc1fd1d72u, 0x10a535deu, 0x49ba1a93u, 0x08a0bd23u, 0x93607cc8u, 0x3871ed2du, 0x00000000u}, 
		{0x5f86a5f1u, 0xad6d9ff2u, 0x38a5a93cu, 0xedad8e2fu, 0x290774acu, 0xc34ea94eu, 0x8aabfd47u, 0xe2af630au, 0x64daac51u, 0xa7509cacu, 0xa593e524u, 0xe5ce2672u, 0xfc290130u, 0x8ec9c762u, 0xe6b2e567u, 0xae681bdcu, 0x2f37b2edu, 0x36058314u, 0xd34a3e8au, 0x02b9910au, 0x7d01def2u, 0x76d6c448u, 0x57a4e15du, 0x32226e1du, 0x0ce5a6d0u, 0x67f8ebceu, 0x60f5609au, 0x1336d56bu, 0x1bcc0db0u, 0xeaf88bc0u, 0xc3b80b72u, 0x2341a5a6u, 0x00000000u}, 
		{0x04c632b7u, 0x49af65adu, 0xaa637a30u, 0xa2ce28b6u, 0xaf5fe55du, 0xb9db7d7eu, 0xce5a4539u, 0x43babc55u, 0x32e7ddf5u, 0xea1eeaffu, 0x89b0b8c6u, 0xffac2cdeu, 0xb78c3e5cu, 0x9076c231u, 0x733ed8cfu, 0x4fe52a0du, 0x40496db5u, 0xc386b678u, 0x9821a853u, 0xc0b211afu, 0xa0c1d9e7u, 0x55b9b353u, 0x5653f580u, 0x23e20fbfu, 0x0fa2da0eu, 0x73dabc61u, 0x6107bcd8u, 0xfd6e6073u, 0x2dee0ce2u, 0x1da83163u, 0xcfa87155u, 0x15304786u, 0x00000000u}
	},
	{
		{0xe5e7a760u, 0x6c534222u, 0x7f4b681cu, 0xdb46b9f4u, 0x1344e23au, 0xc1f2b3a6u, 0xf0dae111u, 0x53cfcd6fu, 0x245bacc6u, 0x54de384fu, 0x3c3aa742u, 0x57d8775cu, 0xe87e75a6u, 0x68fb1b80u, 0xbacda7ddu, 0xca402480u, 0x5dbc0b7du, 0xb9141aa7u, 0xce793b31u, 0xc4fd1aa2u, 0x3636a986u, 0x9bbc756fu, 0xb2cbc594u, 0xb96e05d1u, 0xa9a50011u, 0xe3cf2d6du, 0xf0cb646au, 0xc18db2e2u, 0x58829ec9u, 0xd9da6ce8u, 0x89cc2742u, 0xef86e44au, 0x00000000u}, 
		{0x70758c9du, 0x778024afu, 0x4f2092f9u, 0x94609654u, 0x831b09e4u, 0xc85b5feau, 0x71d3d03du, 0xf05ed563u, 0x25ae2eb4u, 0x1fdef0adu, 0x6e89f01du, 0xd4bc6dc6u, 0x12bb6dd0u, 0x7fbd3b87u, 0xd16cc3fdu, 0xdddbb88au, 0x4b5396e9u, 0x3b2252adu, 0x202eee97u, 0xc3d6ae4au, 0x85e3ff82u, 0xc034132cu, 0x6d1a751du, 0x63593869u, 0x6232b79du, 0xf870c9a4u, 0x38316f46u, 0x36b12403u, 0xbf93a4b3u, 0x2856e0fcu, 0x71e3e884u, 0x665e7f7cu, 0x00000000u}, 
		{0x75721ac3u, 0xf4d31d73u, 0x302ad522u, 0x46e623a0u, 0x9029d856u, 0xf99753bbu, 0x7f0710d3u, 0x6370f80cu, 0xfead7e11u, 0x34ff47a1u, 0xcdb0b725u, 0x831c0995u, 0xd5c307d5u, 0xe93ddff9u, 0xe960e3dfu, 0xec646bf5u, 0x12687493u, 0x7df1c7fau, 0xae4a4c9au, 0x01266c58u, 0xb052aa04u, 0xdb886242u, 0x45b15076u, 0x5614cd68u, 0x47724874u, 0xeb5e63c9u, 0xb899f523u, 0x8adc8edfu, 0x98eefa16u, 0xb1838bebu, 0x17e83ebeu, 0x892864ceu, 0x00000000u}
	},
	{
		{0x7d77e00cu, 0x87dfd452u, 0x19401155u, 0x59dc5591u, 0xc1a0b767u, 0x93cd039au, 0x86753f92u, 0xa7572a53u, 0xccb84dfdu, 0xe769ef04u, 0x254526d4u, 0xed57c9e0u, 0x53c6311fu, 0xcaa66f5fu, 0xe8c35591u, 0x5e49ea71u, 0x3379296fu, 0xecab34d8u, 0x10c01a62u, 0x83de72f1u, 0x2fa5a055u, 0x740d0265u, 0x174f1278u, 0x381644b7u, 0x8cc2d0c6u, 0xfd450738u, 0xfedc0929u, 0x3685febbu, 0x0619e5a0u, 0x6ed1ab29u, 0x3e4c526du, 0xb4b51a28u, 0x00000000u}, 
		{0x18b2820cu, 0xfc29fa17u, 0xbfc113d4u, 0xab2df787u, 0x279ede48u, 0xa24d8293u, 0x49f17fe2u, 0x77749e31u, 0x45e84a8bu, 0xee115e8cu, 0x0600d779u, 0x3379a19du, 0x62c33c77u, 0x5a7ac859u, 0x4669774eu, 0x3d165045u, 0xe591cb73u, 0x9826948au, 0x76238857u, 0x7cef2800u, 0xcf1b979bu, 0x4c58e55cu, 0x9b468931u, 0xf5f1a7eeu, 0xc0b6d593u, 0xa11f1fa3u, 0x5969e744u, 0xfd080a73u, 0xcb5ea338u, 0x79e676beu, 0xd2e1a76du, 0x7a69fdf6u, 0x00000000u}, 
		{0x64c55e00u, 0x8bb5da3bu, 0x597efd80u, 0xaeae5e09u, 0x9a01d91eu, 0xf17f8107u, 0x3c83bfafu, 0x2fe28c22u, 0x86d00372u, 0xf9589078u, 0x1f444f5au, 0xb9de2843u, 0xf102f4a8u, 0x702ba705u, 0xa259de43u, 0x21339a2cu, 0x4de75dfcu, 0x5484a04du, 0x9a9c920bu, 0x06ef4af0u, 0x608a08bau, 0x27b41d08u, 0x7c088947u, 0x42249cc8u, 0xcc0bfb32u, 0x5c25e794u, 0xa57221e5u, 0x397df448u, 0x3abb4267u, 0xf4eb346au, 0x6b6aaaffu, 0x3a4b1c31u, 0x00000000u}
	}
};
