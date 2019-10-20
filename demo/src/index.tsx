import React from 'react';
import ReactDOM from 'react-dom';
import Demo from './Demo';
import { DuckDBAPI } from './DuckDB';
import { Terminal } from './Terminal';
import { AppContextProvider, IAppContext } from './AppContext';

import './index.css';
import './fonts/fonts.css';

const terminal = new Terminal();
const duckdb = new DuckDBAPI();

duckdb.init();

const appContext: IAppContext = {
    duckdb: duckdb,
    terminal: terminal,
};

ReactDOM.render(
    <AppContextProvider value={appContext}>
        <Demo />
    </AppContextProvider>,
    document.getElementById('root') as HTMLElement
);
