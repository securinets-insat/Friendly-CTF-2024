# Description

Aziz sent me these files and challenged me to find the hidden flag. I've been struggling with it for a while
—can you help me solve it and uncover the flag?


# solver

```
╰─➤  zsteg chess_.png
b1,rgb,lsb,xy       .. text: "Securinets{try_touse_thiskey_toreveal_ahint}"
b1,rgba,msb,xy      .. file: OpenPGP Public Key
b1,abgr,msb,xy      .. file: OpenPGP Secret Key
b4,abgr,msb,xy      .. file: RDI Acoustic Doppler Current Profiler (ADCP)
```

```
╰─➤  exiftool simplescreenrecorder-2024-09-19_14.24.08.mp4 
.....
Comment                         : see what you can do with this 59 17 23 5 1 83 65 74 19 26 15 28 7 27 113 23 0 24 92 50 54 26 28 27 48 10 17 86 60 28 10 1 22 19 11 2 30 38 17 28 0 1 26 82
Media Data Size                 : 122614
Media Data Offset               : 39066
Image Size                      : 294x296
Megapixels                      : 0.087
Avg Bitrate                     : 27 kbps
Rotation                        : 0
```

XOR one by one (char)<br>
Securinets{try_touse_thiskey_toreveal_ahint}<br>
59 17 23 5 1 83 65 74 19 26 15 28 7 27 113 23 0 24 92 50 54 26 28 27 48 10 17 86 60 28 10 1 22 19 11 2 30 38 17 28 0 1 26 82
<br>
you will get https://github.com/WintrCat/chessencryption/
<br>
use this repo to decode pgn (chess moves)

this is the script from the repo i just run it on the pgn from the video
```
from time import time
from math import log2
from chess import pgn, Board
from util import get_pgn_games


###
### Pass in a PGN string of 1 or more games
### and also the file path that it should write to in the end
###
def decode(pgn_string: str, output_file_path: str):
    start_time = time()

    total_move_count = 0

    # load games from pgn file
    games: list[pgn.Game] = get_pgn_games(pgn_string)

    # convert moves to binary and write to output file
    with open(output_file_path, "w") as output_file:
        output_file.write("")

    output_file = open(output_file_path, "ab")
    output_data = ""

    for game_index, game in enumerate(games):
        chess_board = Board()

        game_moves = list(game.mainline_moves())
        total_move_count += len(game_moves)

        for move_index, move in enumerate(game_moves):
            # get UCIs of legal moves in current position
            legal_move_ucis = [
                legal_move.uci()
                for legal_move in list(chess_board.generate_legal_moves())
            ]

            # get binary of the move played, using its index in the legal moves
            move_binary = bin(
                legal_move_ucis.index(move.uci())
            )[2:]

            # if this is the last move of the last game,
            # binary cannot go over a total length multiple of 8
            if (
                game_index == len(games) - 1 
                and move_index == len(game_moves) - 1
            ):
                max_binary_length = min(
                    int(log2(
                        len(legal_move_ucis)
                    )),
                    8 - (len(output_data) % 8)
                )
            else:
                max_binary_length = int(log2(
                    len(legal_move_ucis)
                ))

            # Pad move binary to meet max binary length
            required_padding = max(0, max_binary_length - len(move_binary))
            move_binary = ("0" * required_padding) + move_binary

            # play move on board
            chess_board.push_uci(move.uci())

            # add move binary to output data string
            output_data += move_binary

            # if output binary pool is multiple of 8, flush it to file
            if len(output_data) % 8 == 0:
                output_file.write(
                    bytes([
                        int(output_data[i * 8 : i * 8 + 8], 2)
                        for i in range(len(output_data) // 8)
                    ])
                )
                output_data = ""

    print(
        "\nsuccessfully decoded pgn with "
        + f"{len(games)} game(s), {total_move_count} total move(s)"
        + f"({round(time() - start_time, 3)}s)."
    )

decode("1. g3 Na6 2. g4 Nb4 3. g5 Nc6 4. h3 Na5 5. f3 Rb8 6. h4 e6 7. Nc3 Nc4 8. Rh2 Qf6 9. gxf6 Nxb2 10. Kf2 Nxd1+ 11. Nxd1 h6 12. Ke1 Be7 13. Bg2 Bd6 14. Bh1 Kf8 15. Ne3 Ke8 16. Nc4 Ra8 17. Nb2 Rb8 18. Nd1 Bxh2 19. Nf2 Kf8 20. Kf1 Nxf6 21. Kg2 Nh5 22. Nd1 Rg8 23. Nf2 Nf6 24. Ng4 Ke8 25. Ne3 Rh8 26. Nf1 Be5 27. Nh2 b5 28. Ba3 Ba6 29. Nh3 d6 30. Rf1 Bd4 31. Ng1 Kd7 32. Bxd6 Rb7 33. Be7 Be5 34. Bd6 Ba1 *", "output")
```