# Pirma užduotis
# v0.1
* Realizuota programa, kuri nuskaito vartotojų įvedamus reikiamus duomenis: studento vardą ir pavardę, namų darbų ir egzamino rezultatus;
* Baigus duomenų įvedimą, suskaičiuojamas galutinis balas (dviejų skaičių po kablelio tikslumu) ir juos pateikia į ekraną (rodomi stulpelių pavadinimai: Pavardė, Vardas, Galutinis (Vid.);
* Programos papildymas: vietoj galutinio balo skaičiavimo su vidurkiu, galima naudoti ir medianą. Tuomet išvedime rodomas tik vienas pasirinktas Galutinis (Vid.) arba Galutinis (Med.);
* Programos papildymas: programa veikia ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto (realizuota naudojant std::vector tipo konteinerį);
* Programos papildymas: yra galimybė pasirinkti, jog mokinio gautieji balai už namų darbus būtų generuojami atsitiktinai;
 # v0.2
 * Realizuota programa, kuri duomenis nuskaito iš failo;
 * Prgramos papildymas: studentai surūšiuojami pagal pavardę;

# v0.3
* Atliktas versijos (v0.2) kodo reorganizavimas (refactoring'as): funkcijos, nauji duomenų tipai (struct’ūros) perkelktos į antraštinius (angl. header (*.h)) failus;
* Failo skaityme panaudotas išimčių valdymas (tikrina ar gerai įvestas failo pavadinimas);

# v0.4
* Sukurta programa (iš versijos v0.1), kuri sugeneruoja atsitiktinius studentų sąrašų failus (pridėti sugeneruoti sąrašai: 1 000, 10 000, 100 000, 1 000 000, 10 000 000);
* Programos papildymas: studentai surūšiuoti (padalinti) į dvi kategorijas: studentai, kurių galutinis balas < 5.0 pavadinti “vargšiukai”, studentai, kurių galutinis balas >= 5.0 pavadinti "kietiakiai". Surūšiuoti studentai išvesti į du naujus failus;
