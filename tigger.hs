module Main
    ( main
    ) where

import Control.Monad
import Data.List (intercalate)
import System.Console.GetOpt
import System.IO
import System.Exit
import System.Environment (getArgs)
import Data.Map (Map)
import qualified Data.Map as Map

data Flag = NoRecurse   -- -n, --no-recurse
          | Verbose     -- -v, --verbose
          | Help        -- -h, --help
          deriving (Eq, Ord, Enum, Show, Bounded)

validFlags :: [OptDescr Flag]
validFlags = [ Option ['n'] ["no-recurse"] (NoArg NoRecurse)
                 "Don't work with tags/files in directories below the current one."
             , Option ['v'] ["verbose"]    (NoArg Verbose)
                 "Print messages when doing something. Primarily for debugging."
             , Option ['h'] ["help"]       (NoArg Help)
                 "Print this help message."
             ]

validCommands :: [String]
validCommands = ["tag", "untag", "files", "tags", "mv", "cp", "rm"]

commandHelp :: String -> String
commandHelp command = (case (Map.lookup command cmdHelpMap) of
    Nothing -> "Error: This command has no help written. This message should not be reachable in any release version."
    Just msgLines -> unlines msgLines)

cmdHelpMap :: Map String [String]
cmdHelpMap = Map.fromList [
      ("tag",
        [ "Usage: tigger [-nv] tag TAG FILE [FILE ...]"
        , "  Tags all FILEs with the tag TAG."
        ])
    , ("untag",
        [ "Usage: tigger [-nv] untag TAG FILE [FILE ...]"
        , "  Removes the tag TAG from all FILEs that have it."
        ])
    , ("files",
        [ "Usage: tigger [-nv] files TAG"
        , "  Lists all files which have the tag TAG."
        ])
    , ("tags",
        [ "Usage: tigger [-nv] tags FILE [FILE ...]"
        , "  Lists all tags for each FILE."
        ])
    , ("mv",
        [ "Usage: tigger [-nv] mv SRCFILE DESTFILE"
        , "  Moves/renames SRCFILE to DESTFILE, and updates the tagging data to reflect the change."
        ])
    , ("cp",
        [ "Usage: tigger [-nv] cp SRCFILE DESTFILE"
        , "  Copies SRCFILE to DESTFILE, and updates the tagging data to reflect the change."
        ])
    , ("rm",
        [ "Usage: tigger [-nv] rm FILE [FILE ...]"
        , "  Deletes all FILEs, and updates the tagging data to reflect the change."
        ])
    ]

usage :: String
usage = usageInfo header validFlags
    where header = "Usage: tigger [-hnv] (" ++ intercalate "|" validCommands ++") [ARGUMENT ...]"

parseArgsOrExit :: [String] -> IO ([Flag], String, [String])
parseArgsOrExit rawArgs = case getOpt RequireOrder validFlags rawArgs of
    (flags, args, []) -> do
        when (length args < 1) $ do
            if (Help `elem` flags)
                then do
                    putStrLn usage
                    exitSuccess
                else do
                    hPutStrLn stderr "Error: No command provided."
                    hPutStrLn stderr usage
                    exitFailure
        let (command:cmdArgs) = args
        when (not (command `elem` validCommands)) $ do
            hPutStrLn stderr ("Error: '" ++ command ++ "' is not a valid command.")
            hPutStrLn stderr usage
            exitFailure
        when (Help `elem` flags) $ do
            putStrLn (commandHelp command)
            exitSuccess
        return (flags, command, cmdArgs)
    (_, _, errors) -> do
        hPutStrLn stderr (concat errors)
        hPutStrLn stderr usage
        exitFailure

main :: IO ()
main = do
    (flags, command, cmdArgs) <- (getArgs >>= parseArgsOrExit)
    putStrLn $ unlines [ "Got flags: " ++ intercalate ", " (map show flags)
                       , "Got command: " ++ command
                       , "Got args: " ++ intercalate " " cmdArgs
                       ]
