import * as React from 'react';
import { DuckDBAPI } from './DuckDB';
import { Terminal } from './Terminal';

export interface IAppContext {
    duckdb: DuckDBAPI,
    terminal: Terminal,
}

const ctx = React.createContext<IAppContext | null>(null);
export const AppContextProvider = ctx.Provider;
export const AppContextConsumer = ctx.Consumer;

export function withAppContext<
    ALL_PROPS extends { appContext?: IAppContext },
    RAW_PROPS = Pick<ALL_PROPS, Exclude<keyof ALL_PROPS, 'appContext'>>
>(Component: React.ComponentClass<ALL_PROPS> | React.StatelessComponent<ALL_PROPS>): React.SFC<RAW_PROPS> {
    return function BoundComponent(props: RAW_PROPS) {
        return (
            <AppContextConsumer>
                {value => <Component {...(Object.assign({} as ALL_PROPS, props, {appContext: value}))}/>}
            </AppContextConsumer>
        );
    };
}
