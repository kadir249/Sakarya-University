--
-- PostgreSQL database dump
--

-- Dumped from database version 12.2
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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: Kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kullanici" (
    "KullaniciID" integer NOT NULL,
    "Adi" character varying(25) NOT NULL,
    "Sifresi" character varying(16) NOT NULL
);


ALTER TABLE public."Kullanici" OWNER TO postgres;

--
-- Name: Kullanici_KullaniciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kullanici_KullaniciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kullanici_KullaniciID_seq" OWNER TO postgres;

--
-- Name: Kullanici_KullaniciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Kullanici_KullaniciID_seq" OWNED BY public."Kullanici"."KullaniciID";


--
-- Name: Kullanici KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."Kullanici_KullaniciID_seq"'::regclass);


--
-- Data for Name: Kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Kullanici" VALUES (2, 'enesay1', '123ea123ea');
INSERT INTO public."Kullanici" VALUES (3, 'bayramozcan', '571905sky');
INSERT INTO public."Kullanici" VALUES (4, 'fikricem', '_34fcs41_');
INSERT INTO public."Kullanici" VALUES (5, 'alphanakan', '-77aaa34-');
INSERT INTO public."Kullanici" VALUES (6, 'alitosun2', '.57at34.');
INSERT INTO public."Kullanici" VALUES (7, 'ilaydakarakisla', '58ncik34.');
INSERT INTO public."Kullanici" VALUES (8, 'eceozalp', '1902teoeo.');
INSERT INTO public."Kullanici" VALUES (9, 'berkbayrak', 'bb2404bb.');
INSERT INTO public."Kullanici" VALUES (10, 'batuhanyalcin', '_46by34_');
INSERT INTO public."Kullanici" VALUES (1, 'kadircelik', '_kc67570609_');
INSERT INTO public."Kullanici" VALUES (11, 'suzancelikkanat', '_sceses34_');
INSERT INTO public."Kullanici" VALUES (12, 'zeynepdinc', '_123zd456_');
INSERT INTO public."Kullanici" VALUES (13, 'mustafacelik', '67mek34.');
INSERT INTO public."Kullanici" VALUES (14, 'ebrucelik', '_57emk34_');
INSERT INTO public."Kullanici" VALUES (15, 'burakkirat', '789sbk456.');
INSERT INTO public."Kullanici" VALUES (16, 'huseyindogan1', 'hsgsd123.');
INSERT INTO public."Kullanici" VALUES (17, 'melekdinc', '.tfmzbd0.');
INSERT INTO public."Kullanici" VALUES (18, 'nevinumut1', '_nfuu5734_');
INSERT INTO public."Kullanici" VALUES (19, 'haydardogan3', 'sahhd0987.');
INSERT INTO public."Kullanici" VALUES (20, 'sevimeser', '_soie571907_');


--
-- Name: Kullanici_KullaniciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kullanici_KullaniciID_seq"', 20, true);


--
-- Name: Kullanici Kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "Kullanici_pkey" PRIMARY KEY ("KullaniciID");


--
-- Name: Kullanici unique_Kullanici_Adi; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "unique_Kullanici_Adi" UNIQUE ("Adi");


--
-- Name: Kullanici unique_Kullanici_Sifresi; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanici"
    ADD CONSTRAINT "unique_Kullanici_Sifresi" UNIQUE ("Sifresi");


--
-- PostgreSQL database dump complete
--

