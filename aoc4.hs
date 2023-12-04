import Data.List
import Data.List.Split
import qualified Data.Set as Set

readLines :: FilePath -> IO [String]
readLines = fmap lines . readFile

readTo :: String -> Int
readTo s = read s :: Int

splitAndGather :: [Char] -> Int -> [[Char]] -> [[Char]]
splitAndGather spl x  = fmap (!! x) . fmap (splitOn spl)

intersectNum :: ([Int],[Int]) -> Int
intersectNum ls = let s1 = Set.fromList $ fst ls
                      s2 = Set.fromList $ snd ls
	              int_len = (length $ Set.intersection s1 s2) -1
		      in if (int_len < 0) then 0 else  if (int_len == 0) then 1 else  (2 ^ int_len)

main = do
  file_in <- readFile "aoc4.txt"
  let file_lines = lines file_in
  let p1 = fmap (filter (\c -> c /= "")) $ fmap (splitOn " ") $ fmap (drop 9) $ splitAndGather "|" 0 file_lines
  let p2 = fmap (filter (\c -> c /= "")) $ fmap (splitOn " ") $ fmap (drop 1)  $ splitAndGather "|" 1 file_lines
  let p1_read = map (map (readTo)) p1
  let p2_read = map (map (readTo)) p2
  let res = fmap (intersectNum) $  zip p1_read p2_read
  print $ p1_read
  --print $ p2_read
  --print $ res
  let res2 = foldr (+) 0 res
  print $ res2
