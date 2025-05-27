import { SearchBox } from '@mapbox/search-js-react';

export default function MyComponent() {
  return (
      <SearchBox
        accessToken={import.meta.env.VITE_MAPBOX_TOKEN}
        options={{ language: 'es', country: 'US' }}
      />
    
  );
}
