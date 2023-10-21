      /* Enter your code here */
    if (Fireball *s = dynamic_cast<Fireball *>(spell))
    {
        s->revealFirepower();
    }
    else if (Waterbolt *s = dynamic_cast<Waterbolt *>(spell))
    {
        s->revealWaterpower();
    }
    else if (Frostbite *s = dynamic_cast<Frostbite *>(spell))
    {
        s->revealFrostpower();
    }
    else if (Thunderstorm *s = dynamic_cast<Thunderstorm *>(spell))
    {
        s->revealThunderpower();
    }
    else
    {
        auto name = spell->revealScrollName();
        auto journal = SpellJournal::read();
        vector<vector<size_t> > data(name.size() + 1, vector<size_t>(journal.size() + 1, 0));
        for (size_t i = 0; i < name.size(); ++i) {
            for (size_t j = 0; j < journal.size(); ++j) {
                if (name[i] == journal[j])
                    data[i+1][j+1] = data[i][j] + 1;
                else
                    data[i+1][j+1] = max(data[i][j + 1], data[i + 1][j]);
            }
        }
        cout << data[name.size()][journal.size()] << endl;
    }

