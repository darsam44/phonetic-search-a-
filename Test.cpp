#include "PhoneticFinder.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("v and w")
{
    string text = "who did this i want to verify this";
    CHECK( phonetic::find(text,"who").compare("who") == 0 );
	CHECK( phonetic::find(text,"Vho").compare("who") == 0 );
	CHECK( phonetic::find(text,"Who").compare("who") == 0 );
	CHECK( phonetic::find(text,"who").compare("who") == 0 );
	CHECK( phonetic::find(text,"want").compare("want") == 0 );
	CHECK( phonetic::find(text,"Want").compare("want") == 0 );
	CHECK( phonetic::find(text,"Vant").compare("want") == 0 );
	CHECK( phonetic::find(text,"vant").compare("want") == 0 );
	CHECK( phonetic::find(text,"Verify").compare("verify") == 0 );
	CHECK( phonetic::find(text,"verify").compare("verify") == 0 );
	CHECK( phonetic::find(text,"Werify").compare("verify") == 0 );
	CHECK( phonetic::find(text,"werify").compare("verify") == 0 );
}

TEST_CASE("b and f and p")
{
    string text = "people cant fuy flowers on friday because the store is close";
    CHECK( phonetic::find(text,"buy").compare("fuy") == 0 );
	CHECK( phonetic::find(text,"Peoble").compare("people") == 0 );
	CHECK( phonetic::find(text,"Beofle").compare("people") == 0 );
	CHECK( phonetic::find(text,"feoBle").compare("people") == 0 );
	CHECK( phonetic::find(text,"FeoPle").compare("people") == 0 );
	CHECK( phonetic::find(text,"PeoPle").compare("people") == 0 );
	CHECK( phonetic::find(text,"BeoPle").compare("people") == 0 );
	//
	CHECK( phonetic::find(text,"Flowers").compare("flowers") == 0 );
	CHECK( phonetic::find(text,"Plowers").compare("flowers") == 0 );
	CHECK( phonetic::find(text,"plowers").compare("flowers") == 0 );
	CHECK( phonetic::find(text,"Blowers").compare("flowers") == 0 );
	CHECK( phonetic::find(text,"blowers").compare("flowers") == 0 );
	CHECK( phonetic::find(text,"flowers").compare("flowers") == 0 );
	//
	CHECK( phonetic::find(text,"because").compare("because") == 0 );
	CHECK( phonetic::find(text,"Because").compare("because") == 0 );
	CHECK( phonetic::find(text,"Fecause").compare("because") == 0 );
	CHECK( phonetic::find(text,"fecause").compare("because") == 0 );
	CHECK( phonetic::find(text,"pecause").compare("because") == 0 );
	CHECK( phonetic::find(text,"Pecause").compare("because") == 0 );
	//
	CHECK( phonetic::find(text,"friday").compare("friday") == 0 );
	CHECK( phonetic::find(text,"Friday").compare("friday") == 0 );
	CHECK( phonetic::find(text,"Priday").compare("friday") == 0 );
	CHECK( phonetic::find(text,"priday").compare("friday") == 0 );
	CHECK( phonetic::find(text,"briday").compare("friday") == 0 );
	CHECK( phonetic::find(text,"Briday").compare("friday") == 0 );
}

TEST_CASE("g and j")
{
    string text = "gal jump on the grass ";
	CHECK( phonetic::find(text,"gal").compare("gal") == 0 );
	CHECK( phonetic::find(text,"jal").compare("gal") == 0 );
	CHECK( phonetic::find(text,"Gal").compare("gal") == 0 );
	CHECK( phonetic::find(text,"Jal").compare("gal") == 0 );
	//
	CHECK( phonetic::find(text,"jump").compare("jump") == 0 );
	CHECK( phonetic::find(text,"Jump").compare("jump") == 0 );
	CHECK( phonetic::find(text,"gump").compare("jump") == 0 );
	CHECK( phonetic::find(text,"Gump").compare("jump") == 0 );
	//
	CHECK( phonetic::find(text,"grass").compare("grass") == 0 );
	CHECK( phonetic::find(text,"Grass").compare("grass") == 0 );
	CHECK( phonetic::find(text,"Jrass").compare("grass") == 0 );
	CHECK( phonetic::find(text,"jrass").compare("grass") == 0 );

}

TEST_CASE("c and k and q")
{
    string text = "The cats eat the cakes quickly";
    CHECK( phonetic::find(text,"cats").compare("cats") == 0 );
    CHECK( phonetic::find(text,"Cats").compare("cats") == 0 );
    CHECK( phonetic::find(text,"kats").compare("cats") == 0 );
    CHECK( phonetic::find(text,"Kats").compare("cats") == 0 );
    CHECK( phonetic::find(text,"qats").compare("cats") == 0 );
    CHECK( phonetic::find(text,"Qats").compare("cats") == 0 );
	//
	CHECK( phonetic::find(text,"cakes").compare("cakes") == 0 );
	CHECK( phonetic::find(text,"CaQes").compare("cakes") == 0 );
	CHECK( phonetic::find(text,"Kaqes").compare("cakes") == 0 );
	CHECK( phonetic::find(text,"kaces").compare("cakes") == 0 );
	CHECK( phonetic::find(text,"qaCes").compare("cakes") == 0 );
	CHECK( phonetic::find(text,"Qakes").compare("cakes") == 0 );
	//
	CHECK( phonetic::find(text,"quickly").compare("quickly") == 0 );
	CHECK( phonetic::find(text,"KuicCly").compare("quickly") == 0 );
	CHECK( phonetic::find(text,"quicCly").compare("quickly") == 0 );
	CHECK( phonetic::find(text,"Cuicqly").compare("quickly") == 0 );
}

TEST_CASE("z and s")
{
    string text = "lets go to the zoo";
	CHECK( phonetic::find(text,"lets").compare("lets") == 0 );
	CHECK( phonetic::find(text,"letS").compare("lets") == 0 );
	CHECK( phonetic::find(text,"letz").compare("lets") == 0 );
	CHECK( phonetic::find(text,"letZ").compare("lets") == 0 );
	//
	CHECK( phonetic::find(text,"zoo").compare("zoo") == 0 );
	CHECK( phonetic::find(text,"soo").compare("zoo") == 0 );
	CHECK( phonetic::find(text,"Soo").compare("zoo") == 0 );
}

TEST_CASE("d and t")
{
    string text = "lets go to the doctor";
	CHECK( phonetic::find(text,"leds").compare("lets") == 0 );
	CHECK( phonetic::find(text,"letS").compare("lets") == 0 );
	CHECK( phonetic::find(text,"leDz").compare("lets") == 0 );
	CHECK( phonetic::find(text,"ledZ").compare("lets") == 0 );
	//
	CHECK( phonetic::find(text,"toctor").compare("doctor") == 0 );
	CHECK( phonetic::find(text,"Toctor").compare("doctor") == 0 );
	CHECK( phonetic::find(text,"Doctor").compare("doctor") == 0 );

}

TEST_CASE("o and u")
{
    string text = "lets go to the jerusalem";
	CHECK( phonetic::find(text,"jerusalem").compare("jerusalem") == 0 );
	CHECK( phonetic::find(text,"jerosalem").compare("jerusalem") == 0 );
	CHECK( phonetic::find(text,"jerOsalem").compare("jerusalem") == 0 );
	CHECK( phonetic::find(text,"jerUsalem").compare("jerusalem") == 0 );
	//
	CHECK( phonetic::find(text,"gu").compare("go") == 0 );
	CHECK( phonetic::find(text,"gU").compare("go") == 0 );
	CHECK( phonetic::find(text,"gO").compare("go") == 0 );
}

TEST_CASE("i and y")
{
    string text = "yesterday i bought ice-cream";
	CHECK( phonetic::find(text,"Yce-cream").compare("ice-cream") == 0 );
	CHECK( phonetic::find(text,"yce-cream").compare("ice-cream") == 0 );
	CHECK( phonetic::find(text,"Ice-cream").compare("ice-cream") == 0 );
	//
	CHECK( phonetic::find(text,"Y").compare("i") == 0 );
	CHECK( phonetic::find(text,"I").compare("i") == 0 );
	//
	CHECK( phonetic::find(text,"Yesterdai").compare("yesterday") == 0 );
	CHECK( phonetic::find(text,"iesterdaI").compare("yesterday") == 0 );
	CHECK( phonetic::find(text,"IesterdaY").compare("yesterday") == 0 );
	CHECK( phonetic::find(text,"Yesterday").compare("yesterday") == 0 );
}

TEST_CASE("all")
{
    string text = "I dont like coron virus ";
	CHECK( phonetic::find(text,"vyruZ").compare("virus") == 0 );
	CHECK( phonetic::find(text,"wYrOz").compare("virus") == 0 );
	CHECK( phonetic::find(text,"WirOs").compare("virus") == 0 );
	CHECK( phonetic::find(text,"WirOZ").compare("virus") == 0 );
	CHECK( phonetic::find(text,"virus").compare("virus") == 0 );
	//
	CHECK( phonetic::find(text,"KUrun").compare("coron") == 0 );
	CHECK( phonetic::find(text,"kurOn").compare("coron") == 0 );
	CHECK( phonetic::find(text,"QUron").compare("coron") == 0 );
	//
	CHECK( phonetic::find(text,"lYCe").compare("like") == 0 );
	CHECK( phonetic::find(text,"lIce").compare("like") == 0 );
	CHECK( phonetic::find(text,"lyQe").compare("like") == 0 );
	CHECK( phonetic::find(text,"lYqe").compare("like") == 0 );
}