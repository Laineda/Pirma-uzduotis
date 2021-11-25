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
* Programos papildymas: atlikita programos veikimo greičio (spartos) analizė: t.y. išmatuota programos sparta, išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių: failų kūrimas, duomenų nuskaitymas iš failų, studentų rūšiavimas į dvi grupes/kategorijas, surūšiuotų studentų išvedimas į du naujus failus;
![laikas1](https://user-images.githubusercontent.com/90093949/141686907-72348363-7a5e-48ce-8d18-3bb38d68dd9c.PNG)

# v0.5
* v0.4 vektorių konteineriai perkeisti į list'o konteinerius;
* atlikta veikimo greičio (spartos) analizė: kiek laiko užtruko duomenų nuskaitymas iš failų ir studentų surūšiavim1,as į dvi grupes/kategorijas;
Testavimo sistemos parametrai: CPU 2.50GHz RAM 8.00 GB HDD (SSD)
![laikas2](https://user-images.githubusercontent.com/90093949/141686914-cf214a2b-d967-42d5-9017-a424868235d6.PNG)
Išvada: naudojant vector konteinerius, sparta daug didesnė (nei naudojant list konteinerius);

# v1.0
* Optimizuota studentų rūšiavimo (dalijimo) į dvi kategorijas ("vargšiukų" ir "kietiakų") realizacija: t.y. visiems konteinerių tipams (vector ir list) išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijas:
- 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų";
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai";
* Programos efektyvumui pritaikytas algoritmas std::remove_if;

# Naudojimosi instrukcija
1. Parsisiųsti v1.0.cpp, Funkcijos.cpp ir Funkcijos.h failus;
2. Juos atidaryti naudojant tinkamas programas (Visual Studio 2019 (mano naudota), Code::Block ir t.t.);
3. Paleisti programą;
