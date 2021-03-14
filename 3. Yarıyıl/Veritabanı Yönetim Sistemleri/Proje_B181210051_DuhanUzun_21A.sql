--
-- PostgreSQL database dump
--

-- Dumped from database version 12.0
-- Dumped by pg_dump version 12rc1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: fiyatDegisikligiTR1(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."fiyatDegisikligiTR1"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
    IF NEW."fiyati" <> OLD."fiyati" THEN
        INSERT INTO "public"."FiyatDegisikligiIzle"("oyunKodu", "eskiFiyati", "yeniFiyati", "fiyatDegisiklikTarihi")
        VALUES(OLD."oyunID", OLD."fiyati", NEW."fiyati", CURRENT_TIMESTAMP::TIMESTAMP);
    END IF;

    RETURN NEW;
END;
$$;


ALTER FUNCTION public."fiyatDegisikligiTR1"() OWNER TO postgres;

--
-- Name: kayitekle(character varying, character varying, character varying, character varying, character, character); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayitekle(adi character varying, soyadi character varying, eposta character varying, sifre character varying, telefonno character, kartno character) RETURNS void
    LANGUAGE plpgsql
    AS $$  
BEGIN
 INSERT INTO "public"."Kisi"
("adi", "soyadi", "epostaAdresi", "sifresi", "kisiTuru")
VALUES (adi, soyadi, eposta, sifre, 'Kullanıcı');
   
INSERT INTO "public"."Kullanici"
("kisiID", "telefonNumarasi", "kartNumarasi")
VALUES ((SELECT MAX("Kisi"."kisiID") FROM "Kisi"), telefonNo, kartNo);

END;
$$;


ALTER FUNCTION public.kayitekle(adi character varying, soyadi character varying, eposta character varying, sifre character varying, telefonno character, kartno character) OWNER TO postgres;

--
-- Name: kisiEkleTR1(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."kisiEkleTR1"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
    NEW."soyadi" = UPPER(NEW."soyadi");
    NEW."soyadi" = LTRIM(NEW."soyadi");
    NEW."adi" = LTRIM(NEW."adi");
    RETURN NEW;
END;
$$;


ALTER FUNCTION public."kisiEkleTR1"() OWNER TO postgres;

--
-- Name: kullanicisepeti(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kullanicisepeti() RETURNS TABLE(kullaniciid integer, oyunid character, oyunidsi character, sepetid integer)
    LANGUAGE plpgsql
    AS $$
BEGIN
    RETURN QUERY SELECT * FROM "KullaniciOyunu" INNER JOIN "OyunSepeti"
  ON "KullaniciOyunu"."oyunID" = "OyunSepeti"."oyunID";
END;
$$;


ALTER FUNCTION public.kullanicisepeti() OWNER TO postgres;

--
-- Name: oyunanahtariara(character); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.oyunanahtariara(oyunkodu character) RETURNS TABLE(oyunid character, oyunanahtarikodu character)
    LANGUAGE plpgsql
    AS $$
BEGIN
    RETURN QUERY SELECT "oyunID", "kodu" FROM "public"."OyunAnahtari"
                 WHERE "oyunID" = oyunKodu;
END;
$$;


ALTER FUNCTION public.oyunanahtariara(oyunkodu character) OWNER TO postgres;

--
-- Name: platformDegisikligiTR1(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."platformDegisikligiTR1"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
    IF NEW."platformID" <> OLD."platformID" THEN
        INSERT INTO "public"."OyunPlatformDegisikligiIzle"("oyunId", "eskiPlatform", "yeniPlatform", "degisiklikTarihi")
        VALUES(OLD."oyunID", OLD."platformID", NEW."platformID", CURRENT_TIMESTAMP::TIMESTAMP);
    END IF;

    RETURN NEW;
END;
$$;


ALTER FUNCTION public."platformDegisikligiTR1"() OWNER TO postgres;

--
-- Name: sepetolustur(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.sepetolustur() RETURNS void
    LANGUAGE plpgsql
    AS $$  
BEGIN
 INSERT INTO "public"."Sepet"
("kullaniciID")
VALUES ((SELECT MAX("Kullanici"."kullaniciID") FROM "Kullanici"));
END;
$$;


ALTER FUNCTION public.sepetolustur() OWNER TO postgres;

--
-- Name: urunDegisikligiTR1(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."urunDegisikligiTR1"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
    IF NEW."adedi" <> OLD."adedi" THEN
        INSERT INTO "public"."UrunDegisikligiIzle"("oyunKodu", "oyunAdi", "eskiMiktar", "yeniMiktar", "degisiklikTarihi")
        VALUES(OLD."oyunID", OLD."adi", OLD."adedi", NEW."adedi", CURRENT_TIMESTAMP::TIMESTAMP);
    END IF;

    RETURN NEW;
END;
$$;


ALTER FUNCTION public."urunDegisikligiTR1"() OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: Admin; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Admin" (
    "kisiID" integer NOT NULL,
    "adminID" integer NOT NULL
);


ALTER TABLE public."Admin" OWNER TO postgres;

--
-- Name: Admin_adminID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Admin_adminID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Admin_adminID_seq" OWNER TO postgres;

--
-- Name: Admin_adminID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Admin_adminID_seq" OWNED BY public."Admin"."adminID";


--
-- Name: Admin_kisiID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Admin_kisiID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Admin_kisiID_seq" OWNER TO postgres;

--
-- Name: Admin_kisiID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Admin_kisiID_seq" OWNED BY public."Admin"."kisiID";


--
-- Name: FiyatDegisikligiIzle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."FiyatDegisikligiIzle" (
    "kayitNo" integer NOT NULL,
    "oyunKodu" character(5) NOT NULL,
    "eskiFiyati" real NOT NULL,
    "yeniFiyati" real NOT NULL,
    "fiyatDegisiklikTarihi" timestamp without time zone NOT NULL
);


ALTER TABLE public."FiyatDegisikligiIzle" OWNER TO postgres;

--
-- Name: FiyatDegisikligiIzle_kayitNo_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."FiyatDegisikligiIzle_kayitNo_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."FiyatDegisikligiIzle_kayitNo_seq" OWNER TO postgres;

--
-- Name: FiyatDegisikligiIzle_kayitNo_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."FiyatDegisikligiIzle_kayitNo_seq" OWNED BY public."FiyatDegisikligiIzle"."kayitNo";


--
-- Name: Kisi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kisi" (
    "kisiID" integer NOT NULL,
    adi character varying(40) NOT NULL,
    soyadi character varying(25) NOT NULL,
    "epostaAdresi" character varying(60) NOT NULL,
    sifresi character varying(16) NOT NULL,
    "kisiTuru" character varying(9) NOT NULL
);


ALTER TABLE public."Kisi" OWNER TO postgres;

--
-- Name: Kisi_kisiID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kisi_kisiID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kisi_kisiID_seq" OWNER TO postgres;

--
-- Name: Kisi_kisiID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Kisi_kisiID_seq" OWNED BY public."Kisi"."kisiID";


--
-- Name: Kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kullanici" (
    "kisiID" integer NOT NULL,
    "kullaniciID" integer NOT NULL,
    "telefonNumarasi" character(14) NOT NULL,
    "kartNumarasi" character(19) NOT NULL
);


ALTER TABLE public."Kullanici" OWNER TO postgres;

--
-- Name: KullaniciOyunu; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KullaniciOyunu" (
    "kullaniciID" integer NOT NULL,
    "oyunID" character(5) NOT NULL
);


ALTER TABLE public."KullaniciOyunu" OWNER TO postgres;

--
-- Name: KullaniciOyunu_kullaniciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullaniciOyunu_kullaniciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullaniciOyunu_kullaniciID_seq" OWNER TO postgres;

--
-- Name: KullaniciOyunu_kullaniciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullaniciOyunu_kullaniciID_seq" OWNED BY public."KullaniciOyunu"."kullaniciID";


--
-- Name: Kullanici_kisiID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kullanici_kisiID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kullanici_kisiID_seq" OWNER TO postgres;

--
-- Name: Kullanici_kisiID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Kullanici_kisiID_seq" OWNED BY public."Kullanici"."kisiID";


--
-- Name: Kullanici_kullaniciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kullanici_kullaniciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kullanici_kullaniciID_seq" OWNER TO postgres;

--
-- Name: Kullanici_kullaniciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Kullanici_kullaniciID_seq" OWNED BY public."Kullanici"."kullaniciID";


--
-- Name: Oyun; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Oyun" (
    "oyunID" character(5) NOT NULL,
    adi character varying(80) NOT NULL,
    fiyati real NOT NULL,
    resmi character varying(200) NOT NULL,
    adedi smallint NOT NULL,
    "cikisTarihi" date NOT NULL,
    aciklamasi character varying(2044) NOT NULL
);


ALTER TABLE public."Oyun" OWNER TO postgres;

--
-- Name: OyunAnahtari; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyunAnahtari" (
    "oyunID" character(5) NOT NULL,
    "oyunAnahtariID" integer NOT NULL,
    kodu character(17) NOT NULL
);


ALTER TABLE public."OyunAnahtari" OWNER TO postgres;

--
-- Name: OyunAnahtari_oyunAnahtariID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyunAnahtari_oyunAnahtariID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyunAnahtari_oyunAnahtariID_seq" OWNER TO postgres;

--
-- Name: OyunAnahtari_oyunAnahtariID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyunAnahtari_oyunAnahtariID_seq" OWNED BY public."OyunAnahtari"."oyunAnahtariID";


--
-- Name: OyunPlatformDegisikligiIzle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyunPlatformDegisikligiIzle" (
    "kayitNo" integer NOT NULL,
    "oyunId" character(5) NOT NULL,
    "eskiPlatform" character(3) NOT NULL,
    "yeniPlatform" character(3) NOT NULL,
    "degisiklikTarihi" timestamp without time zone NOT NULL
);


ALTER TABLE public."OyunPlatformDegisikligiIzle" OWNER TO postgres;

--
-- Name: OyunPlatformDegisikligiIzle_kayitNo_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyunPlatformDegisikligiIzle_kayitNo_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyunPlatformDegisikligiIzle_kayitNo_seq" OWNER TO postgres;

--
-- Name: OyunPlatformDegisikligiIzle_kayitNo_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyunPlatformDegisikligiIzle_kayitNo_seq" OWNED BY public."OyunPlatformDegisikligiIzle"."kayitNo";


--
-- Name: OyunPlatformu; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyunPlatformu" (
    "oyunID" character(5) NOT NULL,
    "platformID" character(3) NOT NULL
);


ALTER TABLE public."OyunPlatformu" OWNER TO postgres;

--
-- Name: OyunSepeti; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyunSepeti" (
    "oyunID" character(5) NOT NULL,
    "sepetID" integer NOT NULL
);


ALTER TABLE public."OyunSepeti" OWNER TO postgres;

--
-- Name: OyunSepeti_sepetID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyunSepeti_sepetID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyunSepeti_sepetID_seq" OWNER TO postgres;

--
-- Name: OyunSepeti_sepetID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyunSepeti_sepetID_seq" OWNED BY public."OyunSepeti"."sepetID";


--
-- Name: OyunTuru; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyunTuru" (
    "oyunID" character(5) NOT NULL,
    "oyunTuruID" character(3) NOT NULL
);


ALTER TABLE public."OyunTuru" OWNER TO postgres;

--
-- Name: Platform; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Platform" (
    "platformID" character(3) NOT NULL,
    adi character varying(6) NOT NULL
);


ALTER TABLE public."Platform" OWNER TO postgres;

--
-- Name: Sepet; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Sepet" (
    "kullaniciID" integer NOT NULL,
    "sepetID" integer NOT NULL
);


ALTER TABLE public."Sepet" OWNER TO postgres;

--
-- Name: Sepet_kullaniciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Sepet_kullaniciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Sepet_kullaniciID_seq" OWNER TO postgres;

--
-- Name: Sepet_kullaniciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Sepet_kullaniciID_seq" OWNED BY public."Sepet"."kullaniciID";


--
-- Name: Sepet_sepetID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Sepet_sepetID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Sepet_sepetID_seq" OWNER TO postgres;

--
-- Name: Sepet_sepetID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Sepet_sepetID_seq" OWNED BY public."Sepet"."sepetID";


--
-- Name: Turu; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Turu" (
    "oyunTuruID" character(3) NOT NULL,
    adi character varying(20) NOT NULL
);


ALTER TABLE public."Turu" OWNER TO postgres;

--
-- Name: UrunDegisikligiIzle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."UrunDegisikligiIzle" (
    "kayitNo" integer NOT NULL,
    "oyunKodu" character(5) NOT NULL,
    "oyunAdi" character(80) NOT NULL,
    "eskiMiktar" smallint NOT NULL,
    "yeniMiktar" smallint NOT NULL,
    "degisiklikTarihi" timestamp without time zone NOT NULL
);


ALTER TABLE public."UrunDegisikligiIzle" OWNER TO postgres;

--
-- Name: UrunDegisikligiIzle_kayitNo_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."UrunDegisikligiIzle_kayitNo_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."UrunDegisikligiIzle_kayitNo_seq" OWNER TO postgres;

--
-- Name: UrunDegisikligiIzle_kayitNo_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."UrunDegisikligiIzle_kayitNo_seq" OWNED BY public."UrunDegisikligiIzle"."kayitNo";


--
-- Name: Admin adminID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin" ALTER COLUMN "adminID" SET DEFAULT nextval('public."Admin_adminID_seq"'::regclass);


--
-- Name: FiyatDegisikligiIzle kayitNo; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."FiyatDegisikligiIzle" ALTER COLUMN "kayitNo" SET DEFAULT nextval('public."FiyatDegisikligiIzle_kayitNo_seq"'::regclass);


--
-- Name: Kisi kisiID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kisi" ALTER COLUMN "kisiID" SET DEFAULT nextval('public."Kisi_kisiID_seq"'::regclass);


--
-- Name: Kullanici kullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici" ALTER COLUMN "kullaniciID" SET DEFAULT nextval('public."Kullanici_kullaniciID_seq"'::regclass);


--
-- Name: OyunPlatformDegisikligiIzle kayitNo; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunPlatformDegisikligiIzle" ALTER COLUMN "kayitNo" SET DEFAULT nextval('public."OyunPlatformDegisikligiIzle_kayitNo_seq"'::regclass);


--
-- Name: Sepet sepetID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sepet" ALTER COLUMN "sepetID" SET DEFAULT nextval('public."Sepet_sepetID_seq"'::regclass);


--
-- Name: UrunDegisikligiIzle kayitNo; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."UrunDegisikligiIzle" ALTER COLUMN "kayitNo" SET DEFAULT nextval('public."UrunDegisikligiIzle_kayitNo_seq"'::regclass);


--
-- Data for Name: Admin; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Admin" VALUES (3, 1);
INSERT INTO public."Admin" VALUES (4, 2);


--
-- Data for Name: FiyatDegisikligiIzle; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."FiyatDegisikligiIzle" VALUES (2, '#RDR2', 300, 200, '2019-12-15 15:45:57.405622');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (3, '#ETS2', 20, 30, '2019-12-17 18:43:44.740833');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (4, '#ETS2', 30, 20, '2019-12-17 18:46:44.503368');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (5, '#ETS2', 20, 30, '2019-12-17 18:56:05.119046');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (6, '#ETS2', 30, 20, '2019-12-17 18:56:12.482923');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (7, '#ETS2', 20, 30, '2019-12-17 18:56:28.696528');
INSERT INTO public."FiyatDegisikligiIzle" VALUES (8, '#ETS2', 30, 20, '2019-12-17 18:56:34.650551');


--
-- Data for Name: Kisi; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Kisi" VALUES (3, 'Duhan ', 'UZUN', 'duhan181999@gmail.com', '2f5c6dx9', 'Admin');
INSERT INTO public."Kisi" VALUES (4, 'Kadir', 'ÇELIK', 'kadircelik249@gmail.com', 'fsd6c3saz', 'Admin');
INSERT INTO public."Kisi" VALUES (20, 'Selim', 'ÖZTÜRK', 'ozturkselim@gmail.com', '123456', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (21, 'Hüseyin', 'HIRA', 'hüseyinhira@gmail.com', '524536256', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (24, 'Akın', 'SARI', 'akinsari18@gmail.com', '2832878437', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (25, 'Hilmi', 'KIRIK', 'hilmikirik06@gmail.com', '9876562131', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (23, 'Mücahid', 'IŞIK', 'mücahidisik54@gmail.com', '232132133', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (26, 'Ertuğrul', 'SERT', 'ertugrulsert65@hotmail.com', '2323211231', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (27, 'Firdevs', 'ASLAN', 'firdevsaslan1998@gmail.com', '19981998', 'Kullanıcı');
INSERT INTO public."Kisi" VALUES (28, 'Melis', 'ARSLAN', 'melis6918@gmail.com', '232114444', 'Kullanıcı');


--
-- Data for Name: Kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Kullanici" VALUES (20, 4, '05078523067   ', '3567-5874-9654-2305');
INSERT INTO public."Kullanici" VALUES (21, 5, '05363315858   ', '1548-6698-5858-5858');
INSERT INTO public."Kullanici" VALUES (23, 6, '05469845343   ', '2312-1233-5653-2322');
INSERT INTO public."Kullanici" VALUES (24, 7, '05426862331   ', '1233-6732-2333-9776');
INSERT INTO public."Kullanici" VALUES (25, 8, '05312112101   ', '0032-1232-4444-5653');
INSERT INTO public."Kullanici" VALUES (26, 9, '05238766654   ', '2321-3333-5654-2212');
INSERT INTO public."Kullanici" VALUES (27, 10, '05436579865   ', '2565-9753-6448-6757');
INSERT INTO public."Kullanici" VALUES (28, 11, '05169831234   ', '8112-5653-7774-9123');


--
-- Data for Name: KullaniciOyunu; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."KullaniciOyunu" VALUES (8, '#ETS2');
INSERT INTO public."KullaniciOyunu" VALUES (10, '#R6  ');
INSERT INTO public."KullaniciOyunu" VALUES (4, '#RDR2');
INSERT INTO public."KullaniciOyunu" VALUES (5, '#FIFA');
INSERT INTO public."KullaniciOyunu" VALUES (7, '#AOE3');
INSERT INTO public."KullaniciOyunu" VALUES (11, '#RDR2');
INSERT INTO public."KullaniciOyunu" VALUES (6, '#R6  ');
INSERT INTO public."KullaniciOyunu" VALUES (9, '#R6  ');
INSERT INTO public."KullaniciOyunu" VALUES (10, '#ETS2');
INSERT INTO public."KullaniciOyunu" VALUES (6, '#FIFA');


--
-- Data for Name: Oyun; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Oyun" VALUES ('#ETS2', 'Euro Truck Simulator 2', 20, 'C:\Users\kadir\Desktop\b181210051\Oyun_Resimleri\\ETS2.jpg', 3, '2012-10-19', 'Simülasyon ve açık dünya türündeki bu oyunda önemli yüklerinizi tırınızla akıl almaz mesafelere teslim edin, Avrupa''yı bir uçtan bir uca dolaşırken yolların kralı olun! İngiltere, Almanya, Fransa, Hollanda ve pek çok diğer ülkede keşfedilecek düzinelerce şehir var. Dayanıklılık, beceri ve hız sınırlarınız zorlanacak.');
INSERT INTO public."Oyun" VALUES ('#FIFA', 'Fifa 20', 150, 'C:\Users\kadir\Desktop\b181210051\Oyun_Resimleri\\FIFA.jpg', 1, '2019-09-10', 'EA Games tarafından geliştirilen bu futbol oyununda ister bir takım yönetin, isterseniz kendi kariyerinizi oluşturun, isterseniz de online olarak başka oyuncularla oynayın. Bu size kalmış!');
INSERT INTO public."Oyun" VALUES ('#AOE3', 'Age of Empires III', 30, 'C:\Users\kadir\Desktop\b181210051\Oyun_Resimleri\\AOE3.jpg', 2, '2009-09-15', 'Age of Empires III Microsoft''a bağlı Ensemble Stüdyoları tarafından geliştirilip, Microsoft Oyun Stüdyoları tarafından yayınlanmış, gerçek zamanlı strateji türünde bir bilgisayar oyunudur.Oyunun temel aldığı konu; Avrupalıların Amerika’da 16. yüzyıl ile 19. yüzyıl tarihleri arasındaki kolonileşme faaliyetleri ve ABD’nin kuruluşudur. Oyunda toplamda 8 Avrupa medeniyeti ve ABD yer almaktadır. ');
INSERT INTO public."Oyun" VALUES ('#R6  ', 'Tom Clancy''s Rainbow Six: Siege', 40, 'C:\Users\kadir\Desktop\b181210051\Oyun_Resimleri\\R6.jpg', 4, '2015-12-01', 'Tom Clancy''s Rainbow Six Siege ile silah kullanma ve imha sanatında ustalaş. Yaşayacağın deneyimin tam merkezinde yoğun yakın mesafe çatışmaları, yüksek öldürme oranları, strateji ve taktik, ekip oyunu, ve şiddetli aksiyon var. Önceki Tom Clancy''s Rainbow Six oyunlarından devralınan zengin miras ile yoğurulmuş bu müthiş silahlı çatışma ve stratejik uzmanlık oyununu deneyimle.');
INSERT INTO public."Oyun" VALUES ('#RDR2', 'Red Dead Redemption 2', 200, 'C:\Users\kadir\Desktop\b181210051\Oyun_Resimleri\\RDR2.jpg', 5, '2019-11-05', 'Red Dead Redemption 2, Rockstar Studios tarafından geliştirilen, Rockstar Games tarafından ise yayınlanan Western temalı aksiyon-macera türü video oyunudur. 2010 yılında çıkan Red Dead Redemption''ın bir kaç yıl gerisinde geçen oyun Red Dead serisinin üçünçü oyunudur.');


--
-- Data for Name: OyunAnahtari; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyunAnahtari" VALUES ('#ETS2', 1, 'X25AS-GD86A-FDHJ3');
INSERT INTO public."OyunAnahtari" VALUES ('#ETS2', 2, 'SA5DX-WQEA8-GHJJ2');
INSERT INTO public."OyunAnahtari" VALUES ('#ETS2', 3, 'G6HNV-PIJ3Q-LKT5F');
INSERT INTO public."OyunAnahtari" VALUES ('#RDR2', 4, 'UI9DA-QWC3V-HFNM1');
INSERT INTO public."OyunAnahtari" VALUES ('#RDR2', 5, 'OKFX6-CZ6GH-ERWQ9');
INSERT INTO public."OyunAnahtari" VALUES ('#RDR2', 6, 'T9D6X-QSAX3-MNC57');
INSERT INTO public."OyunAnahtari" VALUES ('#RDR2', 7, 'YRQSD-QSDX3-MNFF5');
INSERT INTO public."OyunAnahtari" VALUES ('#RDR2', 8, 'K25FG-GA632-TW9S6');
INSERT INTO public."OyunAnahtari" VALUES ('#AOE3', 9, 'GADSC-YUFD5-EWDSF');
INSERT INTO public."OyunAnahtari" VALUES ('#AOE3', 10, 'E6DX3-QD9GV-IYGB3');
INSERT INTO public."OyunAnahtari" VALUES ('#FIFA', 11, 'E9GFS-QZ6AF-ED6S3');
INSERT INTO public."OyunAnahtari" VALUES ('#R6  ', 12, 'R6DC9-SDC3A-GDCX3');
INSERT INTO public."OyunAnahtari" VALUES ('#R6  ', 13, 'R6ED8-IYRF2-QVZ1A');
INSERT INTO public."OyunAnahtari" VALUES ('#R6  ', 14, 'R6YT9-PUGV3-QAX2S');
INSERT INTO public."OyunAnahtari" VALUES ('#R6  ', 15, 'R6KDF-DEDFS-DSCX3');


--
-- Data for Name: OyunPlatformDegisikligiIzle; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyunPlatformDegisikligiIzle" VALUES (1, '#R6  ', 'UP ', 'STM', '2019-12-17 15:39:29.15543');
INSERT INTO public."OyunPlatformDegisikligiIzle" VALUES (2, '#R6  ', 'STM', 'UP ', '2019-12-17 15:39:39.552712');


--
-- Data for Name: OyunPlatformu; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyunPlatformu" VALUES ('#ETS2', 'STM');
INSERT INTO public."OyunPlatformu" VALUES ('#RDR2', 'STM');
INSERT INTO public."OyunPlatformu" VALUES ('#AOE3', 'STM');
INSERT INTO public."OyunPlatformu" VALUES ('#FIFA', 'ORG');
INSERT INTO public."OyunPlatformu" VALUES ('#R6  ', 'UP ');


--
-- Data for Name: OyunSepeti; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyunSepeti" VALUES ('#ETS2', 5);
INSERT INTO public."OyunSepeti" VALUES ('#R6  ', 7);
INSERT INTO public."OyunSepeti" VALUES ('#RDR2', 1);
INSERT INTO public."OyunSepeti" VALUES ('#FIFA', 2);
INSERT INTO public."OyunSepeti" VALUES ('#AOE3', 4);
INSERT INTO public."OyunSepeti" VALUES ('#RDR2', 8);
INSERT INTO public."OyunSepeti" VALUES ('#R6  ', 3);
INSERT INTO public."OyunSepeti" VALUES ('#R6  ', 6);
INSERT INTO public."OyunSepeti" VALUES ('#ETS2', 7);
INSERT INTO public."OyunSepeti" VALUES ('#FIFA', 3);


--
-- Data for Name: OyunTuru; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyunTuru" VALUES ('#ETS2', 'SMN');
INSERT INTO public."OyunTuru" VALUES ('#ETS2', 'ACD');
INSERT INTO public."OyunTuru" VALUES ('#RDR2', 'ACD');
INSERT INTO public."OyunTuru" VALUES ('#RDR2', 'AKS');
INSERT INTO public."OyunTuru" VALUES ('#AOE3', 'SMN');
INSERT INTO public."OyunTuru" VALUES ('#AOE3', 'STR');
INSERT INTO public."OyunTuru" VALUES ('#FIFA', 'FTL');
INSERT INTO public."OyunTuru" VALUES ('#R6  ', 'AKS');
INSERT INTO public."OyunTuru" VALUES ('#R6  ', 'STR');
INSERT INTO public."OyunTuru" VALUES ('#R6  ', 'ONL');
INSERT INTO public."OyunTuru" VALUES ('#FIFA', 'ONL');


--
-- Data for Name: Platform; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Platform" VALUES ('STM', 'Steam');
INSERT INTO public."Platform" VALUES ('ORG', 'Origin');
INSERT INTO public."Platform" VALUES ('UP ', 'Uplay');


--
-- Data for Name: Sepet; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Sepet" VALUES (4, 1);
INSERT INTO public."Sepet" VALUES (5, 2);
INSERT INTO public."Sepet" VALUES (6, 3);
INSERT INTO public."Sepet" VALUES (7, 4);
INSERT INTO public."Sepet" VALUES (8, 5);
INSERT INTO public."Sepet" VALUES (9, 6);
INSERT INTO public."Sepet" VALUES (10, 7);
INSERT INTO public."Sepet" VALUES (11, 8);


--
-- Data for Name: Turu; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Turu" VALUES ('SMN', 'Simülasyon');
INSERT INTO public."Turu" VALUES ('ACD', 'Açık dünya');
INSERT INTO public."Turu" VALUES ('AKS', 'Aksiyon');
INSERT INTO public."Turu" VALUES ('STR', 'Strateji');
INSERT INTO public."Turu" VALUES ('ONL', 'Online');
INSERT INTO public."Turu" VALUES ('FTL', 'Futbol');


--
-- Data for Name: UrunDegisikligiIzle; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."UrunDegisikligiIzle" VALUES (4, '#RDR2', 'Red Dead Redemption 2                                                           ', 50, 5, '2019-12-15 15:32:21.38644');
INSERT INTO public."UrunDegisikligiIzle" VALUES (5, '#FIFA', 'Fifa 20                                                                         ', 1, 2, '2019-12-17 18:58:38.626277');
INSERT INTO public."UrunDegisikligiIzle" VALUES (6, '#FIFA', 'Fifa 20                                                                         ', 2, 1, '2019-12-17 18:58:42.653352');


--
-- Name: Admin_adminID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Admin_adminID_seq"', 3, true);


--
-- Name: Admin_kisiID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Admin_kisiID_seq"', 1, true);


--
-- Name: FiyatDegisikligiIzle_kayitNo_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."FiyatDegisikligiIzle_kayitNo_seq"', 8, true);


--
-- Name: Kisi_kisiID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kisi_kisiID_seq"', 28, true);


--
-- Name: KullaniciOyunu_kullaniciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullaniciOyunu_kullaniciID_seq"', 1, false);


--
-- Name: Kullanici_kisiID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kullanici_kisiID_seq"', 1, false);


--
-- Name: Kullanici_kullaniciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kullanici_kullaniciID_seq"', 11, true);


--
-- Name: OyunAnahtari_oyunAnahtariID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyunAnahtari_oyunAnahtariID_seq"', 5, true);


--
-- Name: OyunPlatformDegisikligiIzle_kayitNo_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyunPlatformDegisikligiIzle_kayitNo_seq"', 2, true);


--
-- Name: OyunSepeti_sepetID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyunSepeti_sepetID_seq"', 1, false);


--
-- Name: Sepet_kullaniciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Sepet_kullaniciID_seq"', 1, false);


--
-- Name: Sepet_sepetID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Sepet_sepetID_seq"', 8, true);


--
-- Name: UrunDegisikligiIzle_kayitNo_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."UrunDegisikligiIzle_kayitNo_seq"', 6, true);


--
-- Name: Admin Admin_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "Admin_pkey" PRIMARY KEY ("kisiID", "adminID");


--
-- Name: FiyatDegisikligiIzle FiyatDegisikligiIzlePK; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."FiyatDegisikligiIzle"
    ADD CONSTRAINT "FiyatDegisikligiIzlePK" PRIMARY KEY ("kayitNo");


--
-- Name: Kisi Kisi_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kisi"
    ADD CONSTRAINT "Kisi_pkey" PRIMARY KEY ("kisiID");


--
-- Name: KullaniciOyunu KullaniciOyunu_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciOyunu"
    ADD CONSTRAINT "KullaniciOyunu_pkey" PRIMARY KEY ("kullaniciID", "oyunID");


--
-- Name: Kullanici Kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "Kullanici_pkey" PRIMARY KEY ("kisiID", "kullaniciID");


--
-- Name: OyunAnahtari OyunAnahtari_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunAnahtari"
    ADD CONSTRAINT "OyunAnahtari_pkey" PRIMARY KEY ("oyunID", "oyunAnahtariID");


--
-- Name: OyunPlatformu OyunPlatformu_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunPlatformu"
    ADD CONSTRAINT "OyunPlatformu_pkey" PRIMARY KEY ("oyunID", "platformID");


--
-- Name: OyunSepeti OyunSepeti_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunSepeti"
    ADD CONSTRAINT "OyunSepeti_pkey" PRIMARY KEY ("oyunID", "sepetID");


--
-- Name: OyunTuru OyunTuru_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunTuru"
    ADD CONSTRAINT "OyunTuru_pkey" PRIMARY KEY ("oyunID", "oyunTuruID");


--
-- Name: Oyun Oyun_oyunID_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oyun"
    ADD CONSTRAINT "Oyun_oyunID_key" UNIQUE ("oyunID");


--
-- Name: Oyun Oyun_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oyun"
    ADD CONSTRAINT "Oyun_pkey" PRIMARY KEY ("oyunID");


--
-- Name: OyunPlatformDegisikligiIzle PK; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunPlatformDegisikligiIzle"
    ADD CONSTRAINT "PK" PRIMARY KEY ("kayitNo");


--
-- Name: Sepet Sepet_kullaniciID_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sepet"
    ADD CONSTRAINT "Sepet_kullaniciID_key" UNIQUE ("kullaniciID");


--
-- Name: Sepet Sepet_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sepet"
    ADD CONSTRAINT "Sepet_pkey" PRIMARY KEY ("kullaniciID", "sepetID");


--
-- Name: UrunDegisikligiIzle UrunDegisikligiIzlePK; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."UrunDegisikligiIzle"
    ADD CONSTRAINT "UrunDegisikligiIzlePK" PRIMARY KEY ("kayitNo");


--
-- Name: Admin unique_Admin_adminID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "unique_Admin_adminID" UNIQUE ("adminID");


--
-- Name: Admin unique_Admin_kisiID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "unique_Admin_kisiID" UNIQUE ("kisiID");


--
-- Name: Kisi unique_Kisi_epostaAdresi; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kisi"
    ADD CONSTRAINT "unique_Kisi_epostaAdresi" UNIQUE ("epostaAdresi");


--
-- Name: Kisi unique_Kisi_kisiID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kisi"
    ADD CONSTRAINT "unique_Kisi_kisiID" UNIQUE ("kisiID");


--
-- Name: Kullanici unique_Kullanici_kisiID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "unique_Kullanici_kisiID" UNIQUE ("kisiID");


--
-- Name: Kullanici unique_Kullanici_kullaniciID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "unique_Kullanici_kullaniciID" UNIQUE ("kullaniciID");


--
-- Name: OyunAnahtari unique_OyunAnahtari_kodu; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunAnahtari"
    ADD CONSTRAINT "unique_OyunAnahtari_kodu" UNIQUE (kodu);


--
-- Name: OyunAnahtari unique_OyunAnahtari_oyunAnahtariID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunAnahtari"
    ADD CONSTRAINT "unique_OyunAnahtari_oyunAnahtariID" UNIQUE ("oyunAnahtariID");


--
-- Name: Platform unique_Plartform_adi; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Platform"
    ADD CONSTRAINT "unique_Plartform_adi" UNIQUE (adi);


--
-- Name: Platform unique_Plartform_platformID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Platform"
    ADD CONSTRAINT "unique_Plartform_platformID" PRIMARY KEY ("platformID");


--
-- Name: Sepet unique_Sepet_sepetID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sepet"
    ADD CONSTRAINT "unique_Sepet_sepetID" UNIQUE ("sepetID");


--
-- Name: Turu unique_Turu_adi; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Turu"
    ADD CONSTRAINT "unique_Turu_adi" UNIQUE (adi);


--
-- Name: Turu unique_Turu_oyunTuruID; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Turu"
    ADD CONSTRAINT "unique_Turu_oyunTuruID" PRIMARY KEY ("oyunTuruID");


--
-- Name: index_kullaniciID1; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "index_kullaniciID1" ON public."Sepet" USING btree ("kullaniciID");


--
-- Name: Kisi kisiKontrol; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER "kisiKontrol" BEFORE INSERT ON public."Kisi" FOR EACH ROW EXECUTE FUNCTION public."kisiEkleTR1"();


--
-- Name: Oyun oyunFiyatiDegistiginde; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER "oyunFiyatiDegistiginde" BEFORE UPDATE ON public."Oyun" FOR EACH ROW EXECUTE FUNCTION public."fiyatDegisikligiTR1"();


--
-- Name: OyunPlatformu oyunPlatformDegistiginde; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER "oyunPlatformDegistiginde" BEFORE UPDATE ON public."OyunPlatformu" FOR EACH ROW EXECUTE FUNCTION public."platformDegisikligiTR1"();


--
-- Name: Oyun urunMiktariDegistiginde; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER "urunMiktariDegistiginde" BEFORE UPDATE ON public."Oyun" FOR EACH ROW EXECUTE FUNCTION public."urunDegisikligiTR1"();


--
-- Name: Admin AdminKisiFK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "AdminKisiFK" FOREIGN KEY ("kisiID") REFERENCES public."Kisi"("kisiID") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Kullanici KullaniciKisiFK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "KullaniciKisiFK" FOREIGN KEY ("kisiID") REFERENCES public."Kisi"("kisiID") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: KullaniciOyunu KullaniciOyunuFK1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciOyunu"
    ADD CONSTRAINT "KullaniciOyunuFK1" FOREIGN KEY ("kullaniciID") REFERENCES public."Kullanici"("kullaniciID");


--
-- Name: KullaniciOyunu KullaniciOyunuFK2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciOyunu"
    ADD CONSTRAINT "KullaniciOyunuFK2" FOREIGN KEY ("oyunID") REFERENCES public."Oyun"("oyunID");


--
-- Name: OyunAnahtari OyunAnahtariFK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunAnahtari"
    ADD CONSTRAINT "OyunAnahtariFK" FOREIGN KEY ("oyunID") REFERENCES public."Oyun"("oyunID");


--
-- Name: OyunPlatformu OyunPlatformuFK1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunPlatformu"
    ADD CONSTRAINT "OyunPlatformuFK1" FOREIGN KEY ("oyunID") REFERENCES public."Oyun"("oyunID");


--
-- Name: OyunPlatformu OyunPlatformuFK2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunPlatformu"
    ADD CONSTRAINT "OyunPlatformuFK2" FOREIGN KEY ("platformID") REFERENCES public."Platform"("platformID");


--
-- Name: OyunSepeti OyunSepetiFK1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunSepeti"
    ADD CONSTRAINT "OyunSepetiFK1" FOREIGN KEY ("oyunID") REFERENCES public."Oyun"("oyunID");


--
-- Name: OyunSepeti OyunSepetiFK2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunSepeti"
    ADD CONSTRAINT "OyunSepetiFK2" FOREIGN KEY ("sepetID") REFERENCES public."Sepet"("sepetID");


--
-- Name: OyunTuru OyunTuruFK1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunTuru"
    ADD CONSTRAINT "OyunTuruFK1" FOREIGN KEY ("oyunID") REFERENCES public."Oyun"("oyunID");


--
-- Name: OyunTuru OyunTuruFK2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyunTuru"
    ADD CONSTRAINT "OyunTuruFK2" FOREIGN KEY ("oyunTuruID") REFERENCES public."Turu"("oyunTuruID");


--
-- Name: Sepet SepetKullaniciFK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sepet"
    ADD CONSTRAINT "SepetKullaniciFK" FOREIGN KEY ("kullaniciID") REFERENCES public."Kullanici"("kullaniciID") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

