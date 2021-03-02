-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Finding out crime Scene
-- SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Finding out inerview from transcript
-- SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2020;
-- Transcript 1
-- “Ah,” said he, “I forgot that I had not seen you for some weeks.
-- It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
-- “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.”
-- He looked from one to the other of us, as if uncertain which to address.
-- Transcript 2
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- Transcript 3
-- As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Security Logs beteen 10:15 and 10 25
-- SELECT license_plate, activity, hour, minute FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND year = 2020;
-- 5P2BI95 | exit | 10 | 16  Patrick | (725) 555-4692 | 2963008352(passport)
-- 94KL13X | exit | 10 | 18  Ernest | (367) 555-5533 | 5773159633 ****
-- 6P58WS2 | exit | 10 | 18  Amber | (301) 555-4174 | 7526138472
-- 4328GD8 | exit | 10 | 19  Danielle | (389) 555-5198 | 8496433585 *****
-- G412CB7 | exit | 10 | 20  Roger | (130) 555-0289 | 1695452385
-- L93JTIZ | exit | 10 | 21  Elizabeth | (829) 555-5269 | 7049073643 ****
-- 322W7JE | exit | 10 | 23  Russell | (770) 555-1861 | 3592750733 *****
-- 0NTHK55 | exit | 10 | 23  Evelyn | (499) 555-9472 | 8294398571
-- FInd People name according to license
-- SELECT name, phone_number, passport_number FROM people WHERE license_plate = "0NTHK55";

-- Atm transacction @ Fifer Street
-- SELECT account_number, transaction_type, amount FROM atm_transactions WHERE atm_location = "Fifer Street" AND month = 7 AND day = 28 AND year = 2020;
-- account_number | transaction_type | amount
-- 28500762 | withdraw | 48  Danielle****
-- 28296815 | withdraw | 20  Bobby
-- 76054385 | withdraw | 60  Madison
-- 49610011 | withdraw | 50  Ernest*****
-- 16153065 | withdraw | 80  Roy
-- 86363979 | deposit | 10   Robert
-- 25506511 | withdraw | 20  Elizabeth ****
-- 81061156 | withdraw | 30  Victoria
-- 26013199 | withdraw | 35  Russell ******
-- Select name FROM people JOIN bank_accounts on people.id = bank_accounts.person_id WHERE account_number = 26013199;
-- Names matching with Parking ,Ernest, Danielle, Elizabeth , Russell

-- Investigating People who called
-- Select caller, duration, receiver FROM phone_calls WHERE month = 7 AND duration <=60 AND day = 28 AND year = 2020;
-- caller | duration | receiver
-- (130) 555-0289 | 51 | (996) 555-8899
-- (499) 555-9472 | 36 | (892) 555-8872
-- (367) 555-5533 | 45 | (375) 555-8161 **Ernest called Berthold | he travelled but berthold doesnt has passpoer
-- (609) 555-5876 | 60 | (389) 555-5198 **(Reciever Danielle) by Kathryn | 6121106406
-- (499) 555-9472 | 50 | (717) 555-1342
-- (286) 555-6063 | 43 | (676) 555-6554
-- (770) 555-1861 | 49 | (725) 555-3243 ****** Russell called Philip | 3391710505 | Rusell travelled but philip doesnt
-- (031) 555-6622 | 38 | (910) 555-3251
-- (826) 555-1652 | 55 | (066) 555-9701
-- (338) 555-6650 | 54 | (704) 555-2131

-- People who took earliest flight out of Fiftyville tomorrow
-- Select origin_airport_id, destination_airport_id, hour, minute FROM flights WHERE month = 7 AND day = 29 AND year = 2020;
-- origin_airport_id | destination_airport_id        hour | Min
-- CSF | Fiftyville Regional Airport | Fiftyville
-- 8 | 6 ->BOS | Logan International Airport | Boston  16 | 0
-- 8 | 11 -> SFO | San Francisco International Airport | San Francisco  12 | 15
-- 8 | 4 -> LHR | Heathrow Airport | London  8 | 20
-- 8 | 1 ->  ORD | O'Hare International Airport | Chicago  9 | 30
-- 8 | 9 -> HND | Tokyo International Airport | Tokyo  15 | 20
--
-- id | origin_airport_id | destination_airport_id | hour | minute
-- 18 | 8 | 6 | 16 | 0  Russell traveling 4C | 6
-- 23 | 8 | 11 | 12 | 15
-- 36 | 8 | 4 | 8 | 20 Ernest 4A | 4
-- 43 | 8 | 1 | 9 | 30
-- 53 | 8 | 9 | 15 | 20
-- Flights
-- Select abbreviation, full_name, city FROM airports WHERE id = 9;

-- Find Pessengers
-- Select seat FROM passengers WHERE flight_id = 18 AND passport_number = 6121106406;
-- Select seat, destination_airport_id FROM passengers JOIN flights on passengers.flight_id = flights.id WHERE id = 18 AND passport_number = 3391710505 AND month = 7 AND day = 29 AND year = 2020;

-- Finding Ernest partner
-- SELECT name, license_plate, passport_number FROM people WHERE phone_number ="(375) 555-8161";

-- Findings
/****** Russell called Philip | 3391710505 | Rusell travelled but philip doesnt
-- **Ernest called Berthold | he travelled but berthold doesnt has passport in db so looks suspecious and they are theif